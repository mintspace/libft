/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:02:19 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/05 10:08:44 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsign(char *s)
{
	char	*r;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ft_atoi(s) > 0)
		return (s);
	r = (char*)malloc(sizeof(s));
	while (s[i] != '\0')
	{
		r[j] = s[i];
		i++;
		j++;
	}
	free(s);
	r[j] = '\0';
	return (r);
}
