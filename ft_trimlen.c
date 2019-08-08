/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:17:13 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/10 14:27:33 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_trimlen(const char *s)
{
	size_t	space_counter;
	size_t	i;

	space_counter = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
	{
		space_counter++;
		i++;
	}
	while (s[i] != '\0')
		i++;
	if (space_counter != i)
		i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
	{
		space_counter++;
		i--;
	}
	return (ft_strlen(s) - space_counter);
}
