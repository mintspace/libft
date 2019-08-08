/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:21:41 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/07 14:00:46 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[j] != '\0' && j < len)
	{
		i = 0;
		while (haystack[i + j] == needle[i] && ((i + j) < len))
		{
			i++;
			if (needle[i] == '\0')
				return ((char*)haystack + j);
		}
		j++;
	}
	return (NULL);
}
