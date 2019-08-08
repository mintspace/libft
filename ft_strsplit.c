/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:42:11 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/13 08:21:40 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		wdcount;
	char	**main_str;

	if (s == NULL)
		return (NULL);
	wdcount = ft_wdcount(s, c);
	main_str = (char**)malloc(sizeof(char*) * (wdcount + 1));
	if (main_str == NULL)
		return (NULL);
	main_str = ft_sfill(s, main_str, wdcount, c);
	return (main_str);
}
