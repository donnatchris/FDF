/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:43:07 by christophed       #+#    #+#             */
/*   Updated: 2025/01/15 08:23:42 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


// Function to generate x_out and y_out
void    project_isometric_map(t_fdf *fdf)
{
    ft_printf("project_isometric_map\n");
    int i;

    i = 0;
    while(fdf->point[i])
    {
        project_isometric_point(fdf->point[i], fdf);
        printf("Point %d : x_out = %.2f, y_out = %.2f\n", i, fdf->point[i]->x_out, fdf->point[i]->y_out);
        i++;
    }
}

// Function to project the points from 3D to 2D by isometric view
void project_isometric_point(t_point *point, t_fdf *fdf)
{
    ft_printf("project_isometric_point\n");
    const double	angle = M_PI / 6;
    const double	cos_angle = cos(angle);
    const double	sin_angle = sin(angle);
    int				x;
    int				y;
    int				z;

    x = point->x * fdf->zoom;
    y = point->y * fdf->zoom;
    if (point->z != 0)
        z = (point->z + fdf->depth) * fdf->zoom;
    else
        z = point->z * fdf->zoom;
    point->x_out = (x - y) * cos_angle + (fdf->win_width / 2 - 100);
    point->y_out = (x + y) * sin_angle - (z) + (fdf->win_height / 2 - 100);
}


// *x_out += SCREEN_WIDTH / 2;
// *y_out += SCREEN_HEIGHT / 2;

// int scale = 10; // Exemple : zoom
// *x_out *= scale;
// *y_out *= scale;