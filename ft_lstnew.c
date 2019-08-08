/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:18:31 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/13 14:29:26 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *str;

	str = (t_list*)malloc(sizeof(t_list));
	if (str == NULL)
		return (NULL);
	if (content == NULL)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		str->content = ft_strldup(content, content_size);
		str->content_size = content_size;
	}
	str->next = NULL;
	return (str);
}
