/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:32:47 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/08 15:37:29 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
