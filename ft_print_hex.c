/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:22:50 by dbubnov           #+#    #+#             */
/*   Updated: 2019/06/21 14:11:35 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(int nbr, char flag)
{
	char *str;

	if (flag == 'x')
		str = "0123456789abcdef";
	if (flag == 'X')
		str = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_print_hex(nbr / 16, flag);
	write(1, &str[nbr % 16], 1);
}
