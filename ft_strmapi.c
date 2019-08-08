/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:30:35 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/08 17:34:48 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (f == NULL || s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (s != NULL && f != NULL)
	{
		while (i < len)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
