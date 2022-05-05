/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_squares.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:20:30 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/16 21:57:04 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	barycentric(t_coord *p, t_coord a, t_coord b, t_coord c)
{
	double	bary1;
	double	bary2;
	double	bary3;

	bary1 = (double)((b.y - c.y) * (p->x - c.x) + (c.x - b.x) * (p->y - c.y))
		/ ((b.y - c.y) * (a.x - c.x) + (c.x - b.x) * (a.y - c.y));
	if (bary1 < 0 || bary1 > 1)
		return (0);
	bary2 = (double)((c.y - a.y) * (p->x - c.x) + (a.x - c.x) * (p->y - c.y))
		/ ((b.y - c.y) * (a.x - c.x) + (c.x - b.x) * (a.y - c.y));
	if (bary2 < 0 || bary2 > 1)
		return (0);
	bary3 = (1 - bary1 - bary2);
	if (bary3 < 0 || bary3 > 1)
		return (0);
	p->z = bary1 * a.z + bary2 * b.z + bary3 * c.z;
	return (1);
}

void	check_pixels(t_coord a, t_coord b, t_coord c, t_data *data)
{
	t_coord	min;
	t_coord	max;
	t_coord	test;

	min.x = ft_min(a.x, b.x, c.x, a.x);
	max.x = ft_max(a.x, b.x, c.x, a.x);
	min.y = ft_min(a.y, b.y, c.y, a.y);
	max.y = ft_max(a.y, b.y, c.y, a.y);
	test.x = min.x;
	test.y = min.y;
	while (test.y < max.y && test.y < 1000)
	{
		while (test.x < max.x && test.x < 1000)
		{
			if (test.x >= 0 && test.y >= 0 && barycentric(&test, a, b, c) == 1)
			{
				test.color = get_color(data, data->color, test.z);
				mlx_pixel_put(data->mlx, data->window,
					test.x, test.y, test.color);
			}
			test.x++;
		}
		test.x = min.x;
		test.y++;
	}
}

void	color_squares(t_data *data)
{
	t_line	line;
	t_coord	a;
	t_coord	b;
	t_coord	c;
	t_coord	d;

	line.startx = 0;
	line.starty = 0;
	while (line.starty < data->map->height - 1)
	{
		while (line.startx < data->map->width - 1)
		{
			count_coordinates(&a, data, line.startx, line.starty);
			count_coordinates(&b, data, line.startx + 1, line.starty);
			count_coordinates(&c, data, line.startx, line.starty + 1);
			count_coordinates(&d, data, line.startx + 1, line.starty + 1);
			check_pixels(a, b, c, data);
			check_pixels(b, c, d, data);
			draw_line(b, c, data, &line);
			line.startx++;
		}
		line.startx = 0;
		line.starty++;
	}
}
