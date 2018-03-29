/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:25:57 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/02 13:12:53 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int		size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char		*ft_itoa(int n)
{
	int				size;
	char			*new;
	unsigned int	nc;

	size = get_len(n);
	nc = n;
	if (n < 0)
	{
		nc = -n;
		size++;
	}
	if (!(new = ft_strnew(size)))
		return (NULL);
	*(new + --size) = nc % 10 + '0';
	while (nc /= 10)
		*(new + --size) = nc % 10 + '0';
	if (n < 0)
		*(new + 0) = '-';
	return (new);
}
