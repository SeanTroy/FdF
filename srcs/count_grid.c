/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:02:25 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/17 11:48:30 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_isometric(int *x, int *y, int z, t_data *data)
{
	double	angle_x;
	double	angle_y;

	angle_x = data->angle_x / 180 * M_PI;
	angle_y = data->angle_y / 180 * M_PI;
	*x = (*x - *y) * cos(angle_x);
	*y = (*x + *y) * sin(angle_y) - (z * (1 - sin(angle_y)));
}

void	zoom_grid(t_coord *coord, t_data *data)
{
	coord->x *= data->zoom;
	coord->y *= data->zoom;
	coord->z *= data->zoom;
}

int	is_line_in_frame(t_coord start, t_coord end)
{
	if ((start.x >= 0 && start.x < 1000 && start.y >= 0 && start.y < 1000)
		|| (end.x >= 0 && end.x < 1000 && end.y >= 0 && end.y < 1000))
		return (1);
	else
		return (0);
}

void	count_coordinates(t_coord *coord, t_data *data, int x, int y)
{
	coord->x = x;
	coord->y = y;
	coord->z = data->map->z[y][x] * data->stretch;
	zoom_grid(coord, data);
	coord->color = get_color(data, data->color, coord->z);
	if (data->isometric == 'y')
		rotate_isometric(&coord->x, &coord->y, coord->z, data);
	if (data->sideview == 'y')
		coord->y = -coord->z;
	if (data->endview == 'y')
	{
		coord->x = coord->y;
		coord->y = -coord->z;
	}
	coord->x += data->shiftx;
	coord->y += data->shifty;
}

void	count_grid(t_data *data, t_map *map)
{
	t_line	line;
	t_coord	a;
	t_coord	b;

	line.startx = 0;
	line.starty = 0;
	while (line.starty < map->height)
	{
		while (line.startx < map->width)
		{
			count_coordinates(&a, data, line.startx, line.starty);
			if (line.startx < map->width - 1)
				count_coordinates(&b, data, line.startx + 1, line.starty);
			if (line.startx < map->width - 1 && is_line_in_frame(a, b) == 1)
				draw_line(a, b, data, &line);
			if (line.starty < map->height - 1)
				count_coordinates(&b, data, line.startx, line.starty + 1);
			if (line.starty < map->height - 1 && is_line_in_frame(a, b) == 1)
				draw_line(a, b, data, &line);
			line.startx++;
		}
		line.startx = 0;
		line.starty++;
	}
}
