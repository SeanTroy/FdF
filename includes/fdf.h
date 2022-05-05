/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:20:48 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/17 16:15:41 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h" /* Libft functions */
# include "mlx.h" /* MinilibX functions */
# include <unistd.h> /* read, write, close */
# include <fcntl.h> /* open */
# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror */
# include <math.h> /* Math functions */

# define KEYB_1 18
# define KEYB_2 19
# define KEYB_3 20
# define KEYB_4 21
# define KEYB_UP 126
# define KEYB_DOWN 125
# define KEYB_LEFT 123
# define KEYB_RIGHT 124
# define KEYB_W 13
# define KEYB_A 0
# define KEYB_S 1
# define KEYB_D 2
# define KEYB_MINUS 27
# define KEYB_PLUS 24
# define KEYB_C 8
# define KEYB_R 15
# define KEYB_H 4
# define KEYB_ESC 53
# define MOUSE_LEFT 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_map
{
	int	height;
	int	width;
	int	mindepth;
	int	maxdepth;
	int	**z;
}	t_map;

typedef struct s_line
{
	int		startx;
	int		starty;
	double	startz;
	double	endz;
	double	deltax;
	double	deltay;
	int		color;
	double	length;
	double	ratio;
}	t_line;

typedef struct s_ctrl
{
	char	visible;
	char	*helpstring;
	char	*ctrl1;
	char	*ctrl2;
	char	*ctrl3;
	char	*ctrl4;
	char	*ctrl5;
	char	*ctrl6;
	char	*ctrl7;
	char	*ctrl8;
	char	*ctrl9;
	char	*ctrl10;
	char	*ctrl11;
	char	*ctrl12;
	char	*ctrl13;
}	t_ctrl;

typedef struct s_coord
{
	int		x;
	int		y;
	double	z;
	int		color;
}	t_coord;

typedef struct s_color
{
	int		middle;
	int		positive;
	int		negative;
	int		red;
	int		green;
	int		blue;
	double	strength;
	int		target;
}	t_color;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;
	double	angle_x;
	double	angle_y;
	int		shiftx;
	int		shifty;
	double	zoom;
	char	sideview;
	char	endview;
	char	isometric;
	double	stretch;
	char	colored;
	t_map	*map;
	t_line	*line;
	t_ctrl	*ctrls;
	t_color	*color;
}	t_data;

void	read_file(char *argv, t_map *values);
void	ft_del2darray(void ***a, int size);
void	ft_del3darray(void ****a, int size3d, int size2d);
void	count_grid(t_data *data, t_map *map);
void	draw_line(t_coord start, t_coord end, t_data *data, t_line *line);
void	initialize_view(t_data *data);
int		rgb_to_int(int r, int g, int b);
void	count_line(t_data *data, t_line *line, int startx, int starty);
void	rotate_isometric(int *x, int *y, int z, t_data *data);
void	zoom_grid(t_coord *coord, t_data *data);
int		key_click(int keycode, t_data *data);
int		mouse_click(int button, int x, int y, t_data *data);
void	display_controls(t_data *data, t_ctrl *strings);
void	toggle_controls(int keycode, t_data *data);
void	color_squares(t_data *data);
void	set_controls(t_ctrl *strings);
int		get_pixelcolor(t_data *data, t_line *line, int pixel_amount);
int		get_color(t_data *data, t_color *color, double z);
void	args_to_colors(int argc, char **argv, t_data *data);
void	error_exit(int fail);
void	count_coordinates(t_coord *coord, t_data *data, int x, int y);
int		is_line_in_frame(t_coord start, t_coord end);

#endif
