/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:21:56 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/13 18:45:38 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;
	t_list *t;

	if (!lst)
		return (NULL);
	node = f(lst);
	t = node;
	while (lst->next)
	{
		lst = lst->next;
		if (!(node->next = f(lst)))
		{
			free(node->next);
			return (NULL);
		}
		node = node->next;
	}
	return (t);
}
