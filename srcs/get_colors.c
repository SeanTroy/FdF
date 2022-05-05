/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:48:48 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/16 12:41:02 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	get_color(t_data *data, t_color *color, double z)
{
	if (z == 0)
		return (color->middle);
	color->strength = ft_abs_double(z)
		/ (data->map->maxdepth * data->zoom * data->stretch);
	if (z > 0)
		color->target = color->positive;
	else
		color->target = color->negative;
	color->red = get_red(color->target) * color->strength
		+ get_red(color->middle) * (1 - color->strength);
	color->green = get_green(color->target) * color->strength
		+ get_green(color->middle) * (1 - color->strength);
	color->blue = get_blue(color->target) * color->strength
		+ get_blue(color->middle) * (1 - color->strength);
	return (rgb_to_int(color->red, color->green, color->blue));
}
