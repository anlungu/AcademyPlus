/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:39:50 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/18 13:08:51 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(*list))))
		return (NULL);
	if (!content)
	{
		content_size = 0;
		list->content = NULL;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		if (list->content == NULL)
		{
			ft_memdel((void **)&list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
	}
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
