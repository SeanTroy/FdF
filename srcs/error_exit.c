/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:03:26 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/15 19:52:32 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(int fail)
{
	if (fail == 0)
		perror("Error");
	if (fail == 1)
		ft_putstr_fd("Error: Empty file\n", 2);
	if (fail == 2)
		ft_putstr_fd("Error: Invalid map, different line sizes\n", 2);
	if (fail == 3)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	if (fail == 4)
		ft_putstr_fd("Error: Wrong amount of characters in color values\n", 2);
	if (fail == 5)
		ft_putstr_fd("Error: Invalid characters in color values\n", 2);
	exit(-1);
}
