/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:33:14 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/16 09:44:53 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_map(int x, int y, t_data *data)
{
	if (data->isometric == 'y')
	{
		data->shiftx = x - (data->zoom * data->map->width / 9);
		data->shifty = y - (data->zoom * data->map->height / 3);
	}
	else if (data->sideview == 'y')
	{
		data->shiftx = x - (data->zoom * data->map->width / 2);
		data->shifty = y;
	}
	else if (data->endview == 'y')
	{
		data->shiftx = x - (data->zoom * data->map->height / 2);
		data->shifty = y;
	}
	else
	{
		data->shiftx = x - (data->zoom * data->map->width / 2);
		data->shifty = y - (data->zoom * data->map->height / 2);
	}
}

int	mouse_click(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_LEFT)
		place_map(x, y, data);
	if (button == SCROLL_UP)
		data->zoom += 1;
	if (button == SCROLL_DOWN && data->zoom > 0)
		data->zoom -= 1;
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	count_grid(data, data->map);
	if (data->colored == 'y')
		color_squares(data);
	if (data->ctrls->visible == 'n')
		mlx_string_put(data->mlx, data->window, 10, 10, 0xFFFFFF,
			data->ctrls->helpstring);
	else if (data->ctrls->visible == 'y')
		display_controls(data, data->ctrls);
	return (0);
}
