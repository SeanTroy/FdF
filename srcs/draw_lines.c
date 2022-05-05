/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:24:26 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/17 16:22:55 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_pixelcolor(t_data *data, t_line *line, int pixel_amount)
{
	double	relative_z;

	if (line->startz == line->endz)
		return (line->color);
	line->ratio = 1 - (pixel_amount / line->length);
	relative_z = line->endz * line->ratio + line->startz * (1 - line->ratio);
	return (get_color(data, data->color, relative_z));
}

void	set_line_values(t_coord start, t_coord end,
			t_line *line, int *pixel_amount)
{
	line->deltax = end.x - start.x;
	line->deltay = end.y - start.y;
	*pixel_amount = sqrt((line->deltax * line->deltax)
			+ (line->deltay * line->deltay));
	line->length = *pixel_amount;
	line->startz = start.z;
	line->endz = end.z;
	line->color = start.color;
	line->deltax /= *pixel_amount;
	line->deltay /= *pixel_amount;
}

void	draw_line(t_coord start, t_coord end, t_data *data, t_line *line)
{
	int		pixel_amount;
	double	pixelx;
	double	pixely;

	set_line_values(start, end, line, &pixel_amount);
	pixelx = start.x;
	pixely = start.y;
	while (pixel_amount > 0)
	{
		if (pixelx >= 0 && pixelx < 1000 && pixely >= 0 && pixely < 1000)
		{
			line->color = get_pixelcolor(data, line, pixel_amount);
			mlx_pixel_put(data->mlx, data->window, round(pixelx),
				round(pixely), line->color);
		}
		pixelx += line->deltax;
		pixely += line->deltay;
		pixel_amount--;
	}
}
