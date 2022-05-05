/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:30:50 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/08 12:36:33 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_abs_double(double number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}
