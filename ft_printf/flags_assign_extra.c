/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_assign_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:54:35 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:18:39 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_c(t_flags *flags)
{
	if (flags->width > 0)
	{
		flags->width--;
		while (flags->width--)
			ft_putchar(' ');
	}
	flags->no_string = 1;
	ft_putchar('\0');
}

char	*type_di(char *str, t_flags *flags, va_list *ap)
{
	if (flags->l == 2)
		str = ft_itoa_long_long(va_arg(*ap, intmax_t));
	else if (flags->l == 1)
		str = ft_itoa_long(va_arg(*ap, long));
	else if (flags->h == 1)
		str = ft_itoa((short)va_arg(*ap, int));
	else if (flags->h == 2)
		str = ft_itoa((signed char)va_arg(*ap, int));
	else
		str = ft_itoa(va_arg(*ap, int));
	if (ft_atoi(str) == 0 && flags->precision_sign == 1)
		str = ft_strdup("");
	return (str);
}
