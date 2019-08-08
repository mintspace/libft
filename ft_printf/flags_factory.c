/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 23:28:38 by metalium          #+#    #+#             */
/*   Updated: 2019/08/05 10:08:22 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags_factory(char *str, t_flags *flags)
{
	flags_filler(str, flags);
	str = flags_easy(str, flags);
	if (ft_atoi(str) != 0)
		str = flags_normal(str, flags);
	str = flags_nightmare(str, flags);
	return (str);
}

char	*flags_easy(char *str, t_flags *flags)
{
	if (flags->precision > 0 && (flags->type == 'd' || flags->type == 'i'))
		str = add_digit_precision(str, flags->precision, *flags);
	if (flags->precision > 0 && (flags->type == 'o' || flags->type == 'O'))
		str = add_digit_precision(str, flags->precision, *flags);
	if (flags->plus == 1 && ft_atoi(str) >= 0)
		str = ft_addchar(str, *flags);
	if (flags->precision > 0 && flags->type == 's')
		str = ft_cut_string(str, flags->precision);
	if (flags->width <= (int)ft_strlen(str))
		flags->width = (int)ft_strlen(str);
	return (str);
}

char	*flags_normal(char *str, t_flags *flags)
{
	if (flags->hash == 1 && (flags->type == 'o' || flags->type == 'O'))
		str = ft_strjoin_free("0", str, 2);
	if (flags->hash == 1 && flags->type == 'x')
		str = ft_strjoin_free("0x", str, 2);
	if (flags->hash == 1 && flags->type == 'X')
		str = ft_strjoin_free("0X", str, 2);
	if (flags->hash == 1 && flags->width <= (((int)ft_strlen(str) + 2)) &&
		flags->type != 'o' && flags->type != 'O')
		flags->width += 2;
	return (str);
}

char	*flags_nightmare(char *str, t_flags *flags)
{
	char *space_or_zero;

	if (flags->zero == 1 || flags->width > 0)
	{
		space_or_zero = get_space_or_zero(str, flags);
		str = (flags->minus == 1) ? ft_strjoin_free(str, space_or_zero, 3)
		: ft_strjoin_free(space_or_zero, str, 3);
	}
	if (flags->zero == 1 && (flags->dash_sign == '-'
		|| flags->dash_sign == '+'))
		str = ft_sign_swap(str, *flags);
	if (flags->hash == 1 && flags->zero == 1 && ft_strlen(str) != 0)
		str = ft_x_swap(str, *flags);
	if (flags->space == 1 && ft_atoi(str) > 0 && flags->plus == 0)
		if (flags->space == 1 && flags->percent != 1 && flags->precision >= 0)
			if (!(ft_strchr(str, ' ')))
				str = ft_strjoin_free(" ", str, 2);
	if (str == NULL && flags->type == 'c')
		str = ft_strnew(1);
	return (str);
}

char	*get_space_or_zero(char *str, t_flags *flags)
{
	char *size_zero_str;

	if ((flags->type == 'o' || flags->type == 'O')
		&& flags->hash == 1 && flags->width <= (int)ft_strlen(str))
		return (ft_strnew(0));
	size_zero_str = ft_strnew(flags->width - ft_strlen(str));
	ft_memset(size_zero_str, flags->space_or_zero,
	(flags->width - ft_strlen(str)));
	return (size_zero_str);
}
