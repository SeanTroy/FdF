/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:32:57 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/16 09:31:33 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_position(t_data *data)
{
	if (data->isometric == 'y')
	{
		data->shiftx = 375;
		data->shifty = 250;
	}
	else if (data->sideview == 'y' || data->endview == 'y')
	{
		data->shiftx = 100;
		data->shifty = 500;
	}
	else
	{
		data->shiftx = 100;
		data->shifty = 250;
	}
}

void	change_viewtype(int keycode, t_data *data)
{
	if (keycode == KEYB_1)
	{
		data->sideview = 'n';
		data->endview = 'n';
		data->isometric = 'y';
	}
	if (keycode == KEYB_2)
	{
		data->sideview = 'n';
		data->endview = 'n';
		data->isometric = 'n';
	}
	if (keycode == KEYB_3)
	{
		data->sideview = 'y';
		data->endview = 'n';
		data->isometric = 'n';
	}
	if (keycode == KEYB_4)
	{
		data->sideview = 'n';
		data->endview = 'y';
		data->isometric = 'n';
	}
	set_position(data);
}

void	move_and_stretch(int keycode, t_data *data)
{
	if (keycode == KEYB_UP)
		data->shifty -= 10;
	if (keycode == KEYB_DOWN)
		data->shifty += 10;
	if (keycode == KEYB_LEFT)
		data->shiftx -= 10;
	if (keycode == KEYB_RIGHT)
		data->shiftx += 10;
	if (keycode == KEYB_W)
		data->angle_y -= 5;
	if (keycode == KEYB_S)
		data->angle_y += 5;
	if (keycode == KEYB_A)
		data->angle_x += 5;
	if (keycode == KEYB_D)
		data->angle_x -= 5;
	if (keycode == KEYB_MINUS)
		data->stretch /= 1.5;
	if (keycode == KEYB_PLUS)
		data->stretch *= 1.5;
	if (keycode == KEYB_R)
		initialize_view(data);
}

int	key_click(int keycode, t_data *data)
{
	if (keycode == KEYB_ESC)
	{
		ft_putstr("Bye bye!\n");
		exit(0);
	}
	if (keycode >= 18 && keycode <= 21)
		change_viewtype(keycode, data);
	if ((keycode >= 123 && keycode <= 126) || (keycode >= 0 && keycode <= 2)
		|| keycode == 13 || keycode == 24 || keycode == 27 || keycode == 15)
		move_and_stretch(keycode, data);
	if (keycode == KEYB_C && data->colored == 'n')
		data->colored = 'y';
	else if (keycode == KEYB_C && data->colored == 'y')
		data->colored = 'n';
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	count_grid(data, data->map);
	if (data->colored == 'y')
		color_squares(data);
	toggle_controls(keycode, data);
	return (0);
}
