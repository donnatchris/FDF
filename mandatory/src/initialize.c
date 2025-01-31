/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:47 by chdonnat          #+#    #+#             */
/*   Updated: 2025/01/29 09:18:50 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Function to initialize fdf
void	init_fdf(t_fdf *fdf, t_point **point)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		free_and_exit(fdf);
	fdf->point = point;
	init_values(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, \
		fdf->win_height, "FdF");
	if (!fdf->win_ptr)
		free_and_exit(fdf);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width, fdf->win_height);
	if (!fdf->img_ptr)
		free_and_exit(fdf);
	fdf->bpp = 24;
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, \
		&fdf->bpp, &fdf->line_length, &fdf->endian);
	if (!fdf->addr)
		free_and_exit(fdf);
}

// Function to initialize values
void	init_values(t_fdf *fdf)
{
	fdf->iso_on = 1;
	fdf->anim_on = 0;
	fdf->win_width = 1600;
	fdf->win_height = 900;
	fdf->originx = (fdf->win_width / 2);
	fdf->originy = (fdf->win_height / 2);
	fdf->x_max = find_x_max(fdf);
	fdf->y_max = find_y_max(fdf);
	fdf->z_max = find_z_max(fdf);
	calculate_center(fdf);
	center(fdf);
	fdf->zoom = starting_zoom(fdf);
	fdf->depth = 0.1;
	fdf->ox = 0;
	fdf->oy = 0;
	fdf->oz = 0;
	fdf->distance = 300;
	fdf->back_color = BLACK;
	fdf->zero_color = WHITE;
	fdf->up_color = DARK_GREEN;
	fdf->low_color = PURPLE;
	fdf->ghost_color = BLACK;
	fdf->menu_color = WHITE;
}

// Function to find central points
void	calculate_center(t_fdf *fdf)
{
	int	n_points;
	int	i;

	n_points = (fdf->x_max + 1) * (fdf->y_max + 1);
	fdf->x_mid = 0;
	fdf->y_mid = 0;
	fdf->z_mid = 0;
	i = 0;
	while (i < n_points)
	{
		fdf->x_mid += fdf->point[i]->x;
		fdf->y_mid += fdf->point[i]->y;
		fdf->z_mid += fdf->point[i]->z;
		i++;
	}
	fdf->x_mid = fdf->x_mid / n_points;
	fdf->y_mid = fdf->y_mid / n_points;
	fdf->z_mid = fdf->z_mid / n_points;
}

// Function to apply central decalage on each point
void	center(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->point[i])
	{
		fdf->point[i]->x = fdf->point[i]->x - fdf->x_mid;
		fdf->point[i]->y = fdf->point[i]->y - fdf->y_mid;
		i++;
	}
}

// Function to calculate the starting value of the zoom variable
int	starting_zoom(t_fdf *fdf)
{
	int	zoom;

	zoom = fdf->originx / fdf->x_max;
	if (zoom < 1)
		zoom = 1;
	else if (zoom > 80)
		zoom = 80;
	return (zoom);
}
