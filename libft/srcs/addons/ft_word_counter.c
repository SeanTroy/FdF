/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:09:30 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/17 15:57:40 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Returns the amount of words in a given string.
* Words in the string are delimited by character 'c'.
*/

#include "libft.h"

int	ft_word_counter(char const *s, char c)
{
	int		cnt;
	size_t	i;

	if (!s || !*s)
		return (0);
	cnt = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (cnt);
}
