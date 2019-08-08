/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:41:18 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:33 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cut_string(char *str, int number)
{
	char	*cut_string;
	int		i;

	if (number >= (int)ft_strlen(str))
		return (str);
	i = 0;
	cut_string = (char*)malloc(sizeof(char) * number + 1);
	while (number > 0)
	{
		cut_string[i] = str[i];
		i++;
		number--;
	}
	cut_string[i] = '\0';
	free(str);
	return (cut_string);
}

char	*add_digit_precision(char *str, int precision, t_flags flags)
{
	char	*zero_str;
	int		zero_len;
	char	*precision_str;
	char	*sign_ptr;

	zero_str = NULL;
	precision_str = NULL;
	if (precision > 0)
	{
		if ((int)(ft_strlen(str)) >= precision && ft_atoi(str) > 0)
			return (str);
		zero_len = (precision - ft_strlen(str));
		if (ft_atoi(str) < 0)
			zero_len++;
		zero_str = ft_strnew(zero_len);
		ft_memset(zero_str, '0', zero_len);
		precision_str = ft_strjoin_free(zero_str, str, 3);
		if (ft_atoi(str) < 0)
		{
			sign_ptr = ft_strchr(precision_str, flags.dash_sign);
			ft_swap(precision_str, sign_ptr);
		}
	}
	return (precision_str);
}
