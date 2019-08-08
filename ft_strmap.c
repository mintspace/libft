/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:41:25 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/08 17:28:08 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
