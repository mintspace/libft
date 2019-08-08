/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:25:20 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:46 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_unsigned_int(char *str)
{
	intmax_t	result;
	char		*s;

	s = NULL;
	result = (4294967295 - (ft_atoi(ft_unsign(str)) - 1));
	s = ft_itoa_size_t(result);
	return (s);
}

int		get_unsigned_size(size_t i)
{
	int		size;

	size = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_size_t(size_t n)
{
	char	*str;
	int		len;

	len = get_unsigned_size(n);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
