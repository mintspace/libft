/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:26:55 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 15:18:33 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags_check_1(t_flags *flags, va_list *ap)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (flags->type == 'd' || flags->type == 'i')
		str = type_di(str, flags, ap);
	if (flags->type == 's')
	{
		tmp = (va_arg(*ap, char *));
		if (tmp == NULL)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(tmp);
	}
	return (str);
}

char	*flags_check_2(t_flags *flags, va_list *ap)
{
	char	*str;

	str = NULL;
	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
	{
		if (flags->type == 'p')
		{
			flags->l = 1;
			flags->hash = 1;
			flags->type = 'x';
		}
		if (flags->l > 0)
			str = ft_itoa_base_long(va_arg(*ap, long long), 16, flags->type);
		else
			str = ft_itoa_base(va_arg(*ap, int), 16, flags->type);
		if (ft_atoi(str) == 0 && flags->precision_sign == 1)
			str = ft_strdup("");
	}
	if (flags->type == 'o' || flags->type == 'O')
	{
		str = ft_itoa_base(va_arg(*ap, int), 8, flags->type);
		if (ft_atoi(str) == 0 && flags->precision_sign == 1 && flags->hash != 1)
			str = ft_strdup("");
	}
	return (str);
}

char	*flags_check_3(t_flags *flags, va_list *ap)
{
	char	*str;
	char	*tmp_str;
	char	c;

	str = NULL;
	if (flags->percent == 1)
		str = ft_strdup("%");
	if (flags->type == 'c')
	{
		c = (char)(va_arg(*ap, int));
		tmp_str = (char*)malloc(2);
		if (tmp_str == NULL)
			return (NULL);
		if (c == 0 || c == -0)
			type_c(flags);
		else if (flags->no_string != 1)
		{
			tmp_str[0] = c;
			tmp_str[1] = '\0';
		}
		str = tmp_str;
	}
	return (str);
}

char	*flags_check_4(t_flags *flags, va_list *ap)
{
	char	*str;

	str = NULL;
	if (flags->type == 'b')
		str = ft_itoa_base(va_arg(*ap, int), 2, flags->type);
	if (flags->precision_sign == 0 && flags->type == 'f')
		flags->precision = 6;
	if (flags->type == 'f')
		str = ft_ftoa(va_arg(*ap, double), flags);
	if (flags->type == 'u' || flags->type == 'U')
	{
		if (flags->l > 0)
			str = ft_itoa_size_t(va_arg(*ap, unsigned int));
		else
			str = ft_itoa_size_t(va_arg(*ap, unsigned int));
	}
	return (str);
}

char	*flags_assign(t_flags *flags, va_list *ap)
{
	char *str;

	str = NULL;
	str = flags_check_1(flags, ap);
	if (str == NULL)
		str = flags_check_2(flags, ap);
	if (str == NULL)
		str = flags_check_3(flags, ap);
	if (str == NULL)
		str = flags_check_4(flags, ap);
	if (flags->type != '_')
		str = flags_factory(str, flags);
	return (str);
}
