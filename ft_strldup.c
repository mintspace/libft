/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:05:41 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/13 14:30:07 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strldup(void const *s, size_t l)
{
	void	*result;
	size_t	i;

	result = malloc(l);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (l--)
	{
		((char*)result)[i] = ((char*)s)[i];
		i++;
	}
	return (result);
}
