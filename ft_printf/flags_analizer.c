/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_analizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:10:18 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:17 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		a_dot(char *str, t_flags *new, int i)
{
	char	*p;

	new->precision_sign = 1;
	while (str[i] == '.')
		i++;
	if (str[i] == new->type)
		new->steps--;
	new->precision = ft_atoi(&str[i]);
	p = ft_itoa(new->precision);
	new->steps += ft_strlen(p);
	i += (ft_strlen(p) - 1);
	free(p);
	return (i);
}

void	a_param_list(t_flags *new, char c)
{
	if (c == ' ')
		new->space = 1;
	if (c == '-')
		new->minus = 1;
	if (c == '+')
		new->plus = 1;
	if (c == '0')
		new->zero = 1;
	if (c == '#')
		new->hash = 1;
	if (c == 'l')
		new->l++;
	if (c == 'h')
		new->h++;
	if (c == ' ' || c == '-' || c == '+' || c == '0'
		|| c == '#' || c == 'l' || c == 'h')
		new->steps++;
}

int		a_width(char *str, t_flags *new, int i)
{
	char	*s;

	new->width = ft_get_width(str);
	s = ft_itoa(new->width);
	new->steps += (ft_strlen(s));
	i += (ft_strlen(s) - 1);
	free(s);
	return (i);
}

t_flags	flags_analizer(char *str)
{
	t_flags new;
	int		i;

	i = 0;
	ft_bzero(&new, sizeof(t_flags));
	new.type = '_';
	new.type = type_rec(str);
	while (str[i] != 'c' && str[i] != 'd' && str[i] != 'e' && str[i] != 'f' &&
			str[i] != 'g' && str[i] != 'i' && str[i] != 'o' && str[i] != 's' &&
			str[i] != 'u' && str[i] != 'U' && str[i] != 'x' && str[i] != 'X' &&
			str[i] != 'f' && str[i] != 'p')
	{
		if (str[i] == '.')
			i = a_dot(str, &new, i);
		if (str[i] == '%')
		{
			new.percent = 1;
			break ;
		}
		a_param_list(&new, str[i]);
		if (str[i] > '0' && str[i] <= '9')
			i = a_width(str, &new, i);
		i++;
	}
	return (new);
}
