/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:55:42 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/16 08:47:11 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(char *str)
{
	int		len;
	int		result;
	int		i;
	char	c;

	len = ft_strlen(str);
	if (len != 6)
		error_exit(4);
	result = 0;
	i = 0;
	while (i < len)
	{
		c = ft_toupper(str[i]);
		if (!(c >= '0' && c <= '9') && !(c >= 'A' && c <= 'F'))
			error_exit(5);
		if (c >= 'A' && c <= 'F')
			c -= 7;
		result = result * 16 + (c - '0');
		i++;
	}
	return (result);
}

void	args_to_colors(int argc, char **argv, t_data *data)
{
	if (argc >= 3)
		data->color->middle = hex_to_int(argv[2]);
	if (argc >= 4)
		data->color->positive = hex_to_int(argv[3]);
	if (argc >= 5)
		data->color->negative = hex_to_int(argv[4]);
}
