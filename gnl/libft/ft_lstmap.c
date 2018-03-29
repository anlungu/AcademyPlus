/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:01:13 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/02 12:49:02 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new;
	t_list	*ret;

	if (!lst)
		return (NULL);
	list = f(lst);
	if (!(new = ft_lstnew(list->content, list->content_size)))
		return (NULL);
	lst = lst->next;
	ret = new;
	while (lst)
	{
		list = f(lst);
		if (!(new->next = ft_lstnew(list->content, list->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
