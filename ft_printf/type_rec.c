/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:10:38 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:47 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	type_rec(char *str)
{
	char	sign;
	int		i;

	i = 0;
	while (str[i] != 'c' && str[i] != 'd' && str[i] != 'e' && str[i] != 'f' &&
			str[i] != 'g' && str[i] != 'i' && str[i] != 'o' && str[i] != 's' &&
			str[i] != 'u' && str[i] != 'U' && str[i] != 'x' && str[i] != '%' &&
			str[i] != 'X' && str[i] != 'f' && str[i] != 'p')
		i++;
	sign = str[i];
	return (sign);
}
