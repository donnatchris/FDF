/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:47 by christophed       #+#    #+#             */
/*   Updated: 2025/01/27 11:17:58 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Print an error message and exit the program
int	error(char *message)
{
	ft_printf("Error\n");
	if (errno)
		perror(message);
	else
		ft_printf("%s\n", message);
	exit (1);
}

// Close a file descriptor and print an error message before exiting the program
void	close_fd_and_error(int fd, char *message)
{
	if (fd >= 0)
		close(fd);
	error(message);
}

// Free the memory allocated for a table of t_points
// and close a file descriptor before exiting the program
void	free_close_fd_and_error(int fd, t_point **tab, char *message)
{
	if (tab)
		free_points_tab(tab);
	close_fd_and_error(fd, message);
}

// Free the memory allocated for a table of t_points
// and exit the program
void	free_and_error(t_point **tab, char *message)
{
	if (tab)
		free_points_tab(tab);
	error(message);
}
