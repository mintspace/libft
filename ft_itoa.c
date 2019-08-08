/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 08:30:43 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/02 14:21:54 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	size(intmax_t i)
{
	int	size;

	if (i == 0)
		return (2);
	size = 1;
	if (i < 0)
	{
		i *= -1;
		size++;
	}
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

static	int	size_long(size_t i)
{
	int	size;

	if (i == 0)
		return (2);
	size = 1;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = size(n);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (--len >= sign)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_long_long(intmax_t n)
{
	char	*str;
	int		len;
	int		sign;
	size_t	ret;

	sign = 0;
	if (n < 0)
		sign = 1;
	ret = (size_t)n;
	len = size_long(ret);
	len += (sign) ? 1 : 0;
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (--len >= sign)
	{
		str[len] = ret % 10 + '0';
		ret /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_long(intmax_t n)
{
	char	*str;
	int		len;
	int		sign;

	len = size(n);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (--len >= sign)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
