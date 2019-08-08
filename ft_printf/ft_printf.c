/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:13:32 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 15:48:14 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *res, int write_count, t_flags *flags)
{
	if (flags->no_string == 0)
		ft_putstr(res);
	if (flags->no_string == 1 && flags->precision_sign == 1)
		write_count--;
	free(res);
	if (flags->no_string == 1)
		write_count++;
	return (write_count);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	t_flags	flags;
	char	*res;
	int		write_count;

	write_count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			write_count++;
			continue ;
		}
		format++;
		flags = flags_analizer(format++);
		res = flags_assign(&flags, &ap);
		write_count = print_string(res, write_count, &flags);
		format += (flags.steps);
		write_count += ft_strlen(res);
	}
	va_end(ap);
	return (write_count);
}
