/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:18:31 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:29 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addchar(char *str, t_flags flags)
{
	char *s;

	s = NULL;
	if (flags.plus == 1)
	{
		s = (char*)malloc(2);
		if (s == NULL)
			return (NULL);
		s[0] = flags.dash_sign;
		s[1] = '\0';
	}
	str = ft_strjoin_free(s, str, 3);
	return (str);
}
