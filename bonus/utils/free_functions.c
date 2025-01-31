/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:12:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/24 11:31:29 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Free the memory allocated for a table of t_points
void	free_points_tab(t_point **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// Free the memory allocated for a table of strings
void	free_str_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// Function to free allocated memory before exiting
int	free_and_exit(t_fdf *fdf)
{
	free_fdf(fdf);
	exit (1);
}

// Function to free the memory allocated for the fdf structure on Linux
void	free_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->point)
			free_points_tab(fdf->point);
		if (fdf->img_ptr)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
		if (fdf->win_ptr)
			mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		if (fdf->mlx_ptr)
		{
			mlx_destroy_display(fdf->mlx_ptr);
			free(fdf->mlx_ptr);
		}
		free(fdf);
	}
}
