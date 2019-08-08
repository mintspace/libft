/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:14:35 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:37 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_width(char *str)
{
	char	*s;
	int		number_width;

	s = str;
	number_width = 0;
	while (*s == ' ' || *s == '+' || *s == '-'
		|| *s == '%' || *s == '#' || *s == '0')
		s++;
	number_width = ft_atoi(s);
	return (number_width);
}
