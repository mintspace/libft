/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:20:50 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:42 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sign_swap(char *str, t_flags flags)
{
	char	*sign_ptr;

	sign_ptr = ft_strchr(str, flags.dash_sign);
	if (flags.dash != 0 || sign_ptr != NULL)
		ft_swap(str, sign_ptr);
	return (str);
}

char	*ft_x_swap(char *str, t_flags flags)
{
	char	*x_ptr;

	x_ptr = ft_strchr(str, flags.type);
	if (flags.hash != 0 && x_ptr != NULL)
		ft_swap(&str[1], x_ptr);
	return (str);
}
