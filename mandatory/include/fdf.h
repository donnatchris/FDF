/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:02:09 by christophed       #+#    #+#             */
/*   Updated: 2025/01/30 09:47:46 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Libraries
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "colors.h"
# include "../../libft/includes/libft.h"
# include "../../mlx_linux/mlx.h"

// Structures

typedef struct s_src_size
{
	int	n_line;
	int	column_max;
}		t_src_size;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	x_out;
	float	y_out;
	int		color;
}			t_point;

typedef struct s_bres
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			color;
	double		total_dist;
	double		current_dist;
}				t_bres;

typedef struct s_color
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_rotation
{
	float		x;
	float		y;
	float		z;
	float		temp_x;
	float		temp_y;
	float		temp_z;
	float		x_proj;
	float		y_proj;
}				t_rotation;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
	int			originx;
	int			originy;
	float		x_max;
	float		y_max;
	float		z_max;
	float		x_mid;
	float		y_mid;
	float		z_mid;
	int			altitude_max;
	float		ox;
	float		oy;
	float		oz;
	float		sinox;
	float		cosox;
	float		sinoy;
	float		cosoy;
	float		sinoz;
	float		cosoz;
	int			zoom;
	float		depth;
	float		distance;
	float		factor;
	int			back_color;
	int			zero_color;
	int			up_color;
	int			low_color;
	int			ghost_color;
	int			menu_color;
	int			iso_on;
	int			anim_on;
	t_point		**point;
}				t_fdf;

/************************************************************************/
/*								color_animation							*/
/************************************************************************/
void	animation(t_fdf *fdf);
void	slow_animation(t_fdf *fdf, int *i, int *j);
void	fast_animation(t_fdf *fdf, int *i, int *j);
void	swap_colors(int *color1, int *color2);

/************************************************************************/
/*								color_manager							*/
/************************************************************************/
void	initialize_colors(t_fdf *fdf);
void	fill_color(t_fdf *fdf);
int		color_manager(float z, t_fdf *fdf);
int		interpolate_color(int color1, int color2, double t);

/************************************************************************/
/*									draw								*/
/************************************************************************/
void	draw_horizontal_line(t_fdf *fdf, int start);
void	draw_vertical_line(t_fdf *fdf, int start);
void	bresenham(t_fdf *fdf, t_bres *bres, int color0, int color1);
void	set_bres_values(t_bres *bres);
void	put_pixel_to_image(t_fdf *fdf, int x, int y, int color);

/************************************************************************/
/*								error_manager							*/
/************************************************************************/
int		error(char *message);
void	close_fd_and_error(int fd, char *message);
void	free_close_fd_and_error(int fd, t_point **tab, char *message);
void	free_and_error(t_point **tab, char *message);

/************************************************************************/
/*								initialize								*/
/************************************************************************/
void	init_fdf(t_fdf *fdf, t_point **point);
void	init_values(t_fdf *fdf);
void	calculate_center(t_fdf *fdf);
void	center(t_fdf *fdf);
int		starting_zoom(t_fdf *fdf);

/************************************************************************/
/*									iso									*/
/************************************************************************/
void	initialize_isometric_view(t_fdf *fdf);
void	project_isometric_point(t_point *point, t_fdf *fdf);

/************************************************************************/
/*									key_handler							*/
/************************************************************************/
int		deal_key(int key, t_fdf *fdf);
void	change_view(int key, t_fdf *fdf);
void	zoom_and_depth(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	translate(int key, t_fdf *fdf);

/************************************************************************/
/*									menu								*/
/************************************************************************/
void	print_menu(t_fdf *fdf);
void	menu_iso(t_fdf *fdf);
void	menu_perspective(t_fdf *fdf);
void	animate_menu(t_fdf *fdf);

/************************************************************************/
/*									perspective							*/
/************************************************************************/
void	initialize_perspective_view(t_fdf *fdf);
void	project_perspective_point(t_point *point, t_fdf *fdf);

/************************************************************************/
/*								read_and_extract						*/
/************************************************************************/
t_point	**read_and_extract(char *file);
void	create_point_tab(t_point **point_tab, char *file, \
	int column_max, int line_max);
void	fill_src(int fd, t_point **src, char *line, t_src_size src_size);
void	fill_coordonates(t_point *point, int x, int y, char *str);
t_point	**allocate_point_memory(t_point **src, int size);

/************************************************************************/
/*									render								*/
/************************************************************************/
int		render(t_fdf *fdf);
void	project_map(t_fdf *fdf);
void	clear_image(t_fdf *fdf);
void	draw_lines(t_fdf *fdf);

/************************************************************************/
/*								count_functions							*/
/************************************************************************/
int		count_columns(char *file);
int		count_lines(char *file);
int		find_x_max(t_fdf *fdf);
int		find_y_max(t_fdf *fdf);
int		find_z_max(t_fdf *fdf);

/************************************************************************/
/*								free_functions							*/
/************************************************************************/
void	free_points_tab(t_point **tab);
void	free_str_tab(char **tab);
int		free_and_exit(t_fdf *fdf);	
int		free_and_exit(t_fdf *fdf);
void	free_fdf(t_fdf *fdf);

/************************************************************************/
/*								utils_functions							*/
/************************************************************************/
long	ft_atoi_long(const char *nptr);
t_fdf	*malloc_fdf(void);
int		compare(float n1, float n2);
int		check_fdf_extension(const char *filename);
int		check_other_columns(int fd, int column_max);

#endif
