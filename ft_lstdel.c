/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:24:08 by dbubnov           #+#    #+#             */
/*   Updated: 2019/05/13 18:19:38 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *swap;
	t_list *t;

	swap = *alst;
	t = *alst;
	while (t != NULL)
	{
		(*del)(swap->content, swap->content_size);
		swap = t->next;
		free(t);
		t = swap;
	}
	*alst = NULL;
}
