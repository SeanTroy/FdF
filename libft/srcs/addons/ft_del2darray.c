/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del2darray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:46:03 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/03 10:46:24 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del2darray(void ***a, int size)
{
	int	i;

	i = 0;
	if (!a || !*a)
		return ;
	while (i < size)
	{
		free(*(*a + i));
		*(*a + i) = NULL;
		i++;
	}
	free(*a);
	*a = NULL;
}
