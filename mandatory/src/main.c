/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:35:06 by chdonnat          #+#    #+#             */
/*   Updated: 2025/01/29 06:46:20 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_point	**point;
	t_fdf	*fdf;
	int		fd;

	errno = 0;
	if (ac != 2)
		error("Wrong number of arguments");
	if (!check_fdf_extension(av[1]))
		error("Invalid file");
	fd = open(av[1], O_RDONLY, 0);
	point = read_and_extract(av[1]);
	fdf = malloc_fdf();
	if (!fdf)
		free_and_error(point, "memory allocation failed");
	ft_bzero(fdf, sizeof(t_fdf));
	init_fdf(fdf, point);
	project_map(fdf);
	draw_lines(fdf);
	print_menu(fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0L, free_and_exit, fdf);
	mlx_loop_hook(fdf->mlx_ptr, render, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
