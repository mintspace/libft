/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:35:25 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:35 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_first_cut(char *str, int precision, double float_num, int i)
{
	while (precision-- > 0)
	{
		float_num *= 10;
		str[i++] = ((int)float_num % 10) + '0';
		if (precision == 1)
		{
			float_num -= (intmax_t)float_num;
			float_num *= 10;
			if ((int)float_num >= 5 && (int)float_num <= 9)
			{
				if (str[i] >= '1' && str[i] <= '9')
				{
					if (str[i] == '9')
						str[i] = '0';
					else
						str[i++]++;
					break ;
				}
			}
		}
		float_num -= (intmax_t)float_num;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_ftoa(double float_num, t_flags *flags)
{
	int			aprox_result;
	intmax_t	left_num;
	char		*left_part;
	char		*right_part;
	int			sign;

	sign = (float_num < 0) ? 1 : 0;
	right_part = NULL;
	float_num *= (float_num < 0) ? -1 : 1;
	left_num = (intmax_t)float_num;
	float_num = float_num - left_num;
	left_part = ft_itoa_long(left_num);
	right_part = right_float_part(float_num, right_part, flags->precision);
	aprox_result = aprox(right_part, float_num, *flags);
	if (aprox_result == 1 || aprox_result == 2)
	{
		left_num++;
		left_part = ft_itoa(left_num);
	}
	if (aprox_result == 1)
		right_part = ft_strnew(0);
	left_part = ft_strjoin(left_part, right_part);
	if (sign == 1)
		left_part = ft_strjoin("-", left_part);
	return (left_part);
}

int		aprox(char *cut_num, double num, t_flags flags)
{
	int	i;
	int original;

	original = ((int)(num *= 10));
	if (flags.precision == 0)
		if (original >= 5 && original <= 9)
			return (1);
	i = ft_strlen(cut_num) - 1;
	while (cut_num[i] != '.')
	{
		if (cut_num[i] == '9' && cut_num[1] == '9')
		{
			cut_num[i] = '0';
			if (cut_num[1] == '0')
				return (2);
		}
		i--;
	}
	cut_num[ft_strlen(cut_num)] = '\0';
	return (0);
}

char	*right_float_part(double float_num, char *right_part, int precision)
{
	char		*str;
	intmax_t	i;

	i = 1;
	if ((str = (char*)malloc(precision + 1)) == NULL)
		return (NULL);
	ft_memset(str, '\0', precision);
	str[0] = '.';
	str = precision_first_cut(str, precision, float_num, i);
	return (right_part = str);
}
