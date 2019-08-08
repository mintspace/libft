/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:17:44 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 14:20:32 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned int nbr, int base, char flag)
{
	char	*str;
	char	*result;
	char	c;

	result = NULL;
	if (flag == 'b')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (nbr >= (unsigned int)base)
		result = ft_itoa_base(nbr / base, base, flag);
	c = str[nbr % base];
	result = f_char_add(result, c);
	return (result);
}

char	*f_char_add(char *str, char c)
{
	char *new;

	if (str == NULL)
		str = ft_strnew(0);
	new = ft_strnew(1);
	new[0] = c;
	str = ft_strjoin_free(str, new, 3);
	return (str);
}

char	*ft_itoa_base_long(size_t nbr, int base, char flag)
{
	char	*str;
	char	*result;
	char	c;

	result = NULL;
	if (flag == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (nbr >= (unsigned int)base)
		result = ft_itoa_base_long(nbr / base, base, flag);
	c = str[nbr % base];
	result = f_char_add(result, c);
	return (result);
}
