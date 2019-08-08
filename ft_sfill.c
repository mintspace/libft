/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:42:11 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/13 08:24:22 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sfill(char const *s, char **main_str, int wdcount, char c)
{
	int	j;
	int	m;
	int	c_counter;

	m = 0;
	while (wdcount--)
	{
		c_counter = ft_chcount(s, c);
		while (*s == c)
			s++;
		while (c_counter > 0)
		{
			j = 0;
			main_str[m] = (char*)malloc(c_counter + 1);
			while (c_counter--)
			{
				main_str[m][j++] = *s;
				s++;
			}
			main_str[m++][j] = '\0';
		}
	}
	main_str[m] = NULL;
	return (main_str);
}
