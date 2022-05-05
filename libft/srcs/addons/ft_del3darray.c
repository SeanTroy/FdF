/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del3darray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:46:58 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/03 10:47:28 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del3darray(void ****a, int size3d, int size2d)
{
	int	i;

	i = 0;
	if (!a || !*a)
		return ;
	while (i < size3d)
	{
		ft_del2darray((void ***)&(*(*a + i)), size2d);
		i++;
	}
	free(*a);
	*a = NULL;
}
