/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:16:25 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/02 15:07:49 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	if (!*str)
		return (0);
	while (*str == ' ' || *str == '\v'
			|| *str == '\t' || *str == '\0'
			|| *str == '\r' || *str == '\n'
			|| *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + (*str - 48);
		str++;
	}
	return (nbr * sign);
}
