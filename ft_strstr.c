/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:45:08 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/01 13:14:39 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[j] != '\0')
	{
		i = 0;
		while (haystack[i + j] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char*)haystack + j);
		}
		j++;
	}
	return (NULL);
}
