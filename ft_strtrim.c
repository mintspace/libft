/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:59:51 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/10 15:12:50 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s) - ft_trimlen(s)) > 0)
	{
		str = ft_malloclen(s);
	}
	else
		str = ft_strdup(s);
	return (str);
}
