/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloclen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:13:58 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/10 14:44:28 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malloclen(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	malloc_len;

	malloc_len = ft_trimlen(s);
	str = (char*)malloc((malloc_len) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	if ((ft_strlen(s) - malloc_len) > 0)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
			i++;
		j = 0;
		while (malloc_len > 0)
		{
			str[j] = s[i];
			malloc_len--;
			j++;
			i++;
		}
		str[j] = '\0';
	}
	return (str);
}
