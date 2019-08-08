/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:20:09 by dbubnov           #+#    #+#             */
/*   Updated: 2019/07/14 16:09:35 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = (len - start) + 1;
	i = 0;
	str = (char*)malloc((len) + 1);
	if (str == NULL)
		return (NULL);
	while (len > 0 && *s != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	if (str == NULL)
		return (NULL);
	return (str);
}
