/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:51:19 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/09 15:00:49 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_start;
	size_t	big_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	big_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc((big_len) + 1);
	if (str == NULL)
		return (NULL);
	str_start = str;
	while (*s1 != '\0')
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (str_start);
}
