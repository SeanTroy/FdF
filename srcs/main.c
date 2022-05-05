/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:17:50 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/16 09:39:50 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Sets the wanted color value (0-255) to the corresponding pixel byte.
Endian 1 = Most significant byte (Alpha) first, order: Alpha, Red, Green, Blue
Endian 0 = Least significant byte (Blue) first, order: Blue, Green, Red, Alpha
Alpha 0 = 100 % visibility, Alpha 255 = 100 % transparency
*/

void	set_pixel_color(t_data *data, int pixel, int x, int y)
{
	if (data->endian == 1)
	{
		data->buffer[pixel + 0] = (uint8_t)0;
		data->buffer[pixel + 1] = (0 + (x + y) / 40);
		data->buffer[pixel + 2] = (0 + (x + y) / 40);
		data->buffer[pixel + 3] = (uint8_t)32;
	}
	else if (data->endian == 0)
	{
		data->buffer[pixel + 0] = (uint8_t)32;
		data->buffer[pixel + 1] = (0 + (x + y) / 40);
		data->buffer[pixel + 2] = (0 + (x + y) / 40);
		data->buffer[pixel + 3] = (uint8_t)0;
	}
}

void	draw_background(t_data *data)
{
	int	pixel;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1000)
	{
		while (x < 1000)
		{
			pixel = (y * data->line_bytes) + (x * 4);
			set_pixel_color(data, pixel, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	initialize_view(t_data *data)
{
	if (data->isometric == 'y')
		data->shiftx = 375;
	else
		data->shiftx = 100;
	if (data->endview == 'y' || data->sideview == 'y')
		data->shifty = 500;
	else
		data->shifty = 250;
	data->zoom = 800 / data->map->width;
	if (data->map->maxdepth > data->map->width)
		data->zoom = 800 / data->map->maxdepth;
	data->stretch = 1;
	data->angle_x = 45;
	data->angle_y = 45;
}

void	initialize_window(t_data *data, t_map *map,
			t_ctrl *ctrls, t_color *color)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1000, 1000, "506th Window");
	data->image = mlx_new_image(data->mlx, 1000, 1000);
	data->buffer = mlx_get_data_addr(data->image, &data->pixel_bits,
			&data->line_bytes, &data->endian);
	draw_background(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	data->map = map;
	data->ctrls = ctrls;
	data->color = color;
	color->middle = 0xFFFFFF;
	color->positive = 0xFF0000;
	color->negative = 0x0000FF;
	data->sideview = 'n';
	data->endview = 'n';
	data->isometric = 'y';
	data->colored = 'n';
	ctrls->visible = 'n';
	set_controls(ctrls);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	t_ctrl	ctrls;
	t_color	color;

	if (argc < 2 || argc > 5)
	{
		ft_putstr("Usage: ./fdf map_filename [color1] [color2] [color3]\n");
		ft_putstr("Enter colors using 6-digit HEX: 000FFF, 123ABC ... ");
		ft_putstr("(Default colors: FFFFFF, FF0000, 0000FF)\n");
		ft_putstr("Allowed characters: 0-9, a-f, A-F\n");
		exit(0);
	}
	read_file(argv[1], &map);
	initialize_window(&data, &map, &ctrls, &color);
	args_to_colors(argc, argv, &data);
	initialize_view(&data);
	count_grid(&data, &map);
	mlx_string_put(data.mlx, data.window, 10, 10, 0xFFFFFF, ctrls.helpstring);
	mlx_key_hook(data.window, key_click, &data);
	mlx_mouse_hook(data.window, mouse_click, &data);
	mlx_loop(data.mlx);
	ft_del2darray((void ***)&map.z, map.height);
	return (0);
}
