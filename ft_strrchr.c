/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:00:32 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/06 16:18:45 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*str != '\0')
		str++;
	while (str >= s)
	{
		if (*str == c)
			return (str);
		str--;
	}
	return (NULL);
}
