/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:54:30 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/15 16:12:05 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_controls(t_data *data, t_ctrl *ctrls)
{
	mlx_string_put(data->mlx, data->window, 10, 10, 0xFFFFFF, ctrls->ctrl1);
	mlx_string_put(data->mlx, data->window, 10, 30, 0xFFFFFF, ctrls->ctrl2);
	mlx_string_put(data->mlx, data->window, 10, 50, 0xFFFFFF, ctrls->ctrl3);
	mlx_string_put(data->mlx, data->window, 10, 70, 0xFFFFFF, ctrls->ctrl4);
	mlx_string_put(data->mlx, data->window, 10, 90, 0xFFFFFF, ctrls->ctrl5);
	mlx_string_put(data->mlx, data->window, 10, 110, 0xFFFFFF, ctrls->ctrl6);
	mlx_string_put(data->mlx, data->window, 10, 130, 0xFFFFFF, ctrls->ctrl7);
	mlx_string_put(data->mlx, data->window, 10, 150, 0xFFFFFF, ctrls->ctrl8);
	mlx_string_put(data->mlx, data->window, 10, 170, 0xFFFFFF, ctrls->ctrl9);
	mlx_string_put(data->mlx, data->window, 10, 190, 0xFFFFFF, ctrls->ctrl10);
	mlx_string_put(data->mlx, data->window, 10, 210, 0xFFFFFF, ctrls->ctrl11);
	mlx_string_put(data->mlx, data->window, 10, 230, 0xFFFFFF, ctrls->ctrl12);
	mlx_string_put(data->mlx, data->window, 10, 250, 0xFFFFFF, ctrls->ctrl13);
}

void	set_controls(t_ctrl *ctrls)
{
	ctrls->helpstring = "H: Show Controls";
	ctrls->ctrl1 = "H: Hide Controls";
	ctrls->ctrl2 = "Left Mouse Click: Place Map";
	ctrls->ctrl3 = "Mouse Scroll Wheel: Zoom In/Out";
	ctrls->ctrl4 = "1: Isometric View";
	ctrls->ctrl5 = "2: Top View";
	ctrls->ctrl6 = "3: Side View (Bottom)";
	ctrls->ctrl7 = "4: Side View (Left)";
	ctrls->ctrl8 = "Arrow Keys: Move Map";
	ctrls->ctrl9 = "W,A,S,D: Rotate Map (in Isometric View)";
	ctrls->ctrl10 = "+/-: Stretch/Shrink Map Dimensions";
	ctrls->ctrl11 = "C: Fill Colors On/Off";
	ctrls->ctrl12 = "R: Reset Values";
	ctrls->ctrl13 = "ESC: Close Program";
}

void	toggle_controls(int keycode, t_data *data)
{
	if (keycode == KEYB_H && data->ctrls->visible == 'n')
	{
		display_controls(data, data->ctrls);
		data->ctrls->visible = 'y';
	}
	else if (keycode == KEYB_H && data->ctrls->visible == 'y')
	{
		mlx_string_put(data->mlx, data->window, 10, 10, 0xFFFFFF,
			data->ctrls->helpstring);
		data->ctrls->visible = 'n';
	}
	if (keycode != KEYB_H && data->ctrls->visible == 'n')
	{
		mlx_string_put(data->mlx, data->window, 10, 10, 0xFFFFFF,
			data->ctrls->helpstring);
	}
	else if (keycode != KEYB_H && data->ctrls->visible == 'y')
		display_controls(data, data->ctrls);
}
