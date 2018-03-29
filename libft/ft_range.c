/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:22:27 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/08 16:24:28 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*list;
	int		i;

	if ((min >= max) || !(list = (int*)malloc(sizeof(int) * (max - min))))
		return (NULL);
	i = 0;
	while (min < max)
		list[i++] = min++;
	list[i] = '\0';
	return (list);
}
