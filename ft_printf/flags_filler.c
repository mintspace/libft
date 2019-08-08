/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:11:25 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:27 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flags_filler(char *str, t_flags *flags)
{
	flags->dash_sign = (flags->plus == 1 && ft_atoi(str) >= 0) ? '+' : '-';
	flags->space_or_zero = (flags->zero == 1) ? '0' : ' ';
	if (flags->precision > 0)
		flags->space_or_zero = ' ';
	if (flags->zero == 1 && flags->minus == 1)
		flags->space_or_zero = ' ';
	if (ft_atoi(str) == 0)
		flags->space_or_zero = ' ';
	if (flags->type == 'p')
	{
		flags->l = 1;
		flags->hash = 1;
		flags->type = 'x';
	}
	if ((flags->type == 'u' || flags->type == 'U')
		&& flags->precision_sign == 1)
	{
		flags->width = flags->precision;
		flags->zero = 1;
		flags->space_or_zero = '0';
	}
}
