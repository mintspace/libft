/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:58:26 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/11 20:19:20 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chcount(char const *s, char c)
{
	int		char_counter;

	char_counter = 0;
	while (*s != '\0')
	{
		while (*s != c && *s != '\0')
		{
			char_counter++;
			s++;
			if (*s == c)
				return (char_counter);
		}
		if (*s != '\0')
			s++;
	}
	return (char_counter);
}
