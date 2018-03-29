/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:01:04 by anlungu           #+#    #+#             */
/*   Updated: 2017/11/27 12:50:13 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *ps;
	unsigned char *pd;

	ps = (unsigned char*)src;
	pd = (unsigned char*)dst;
	if (pd <= ps || (pd + n) <= ps)
		while (n--)
			*pd++ = *ps++;
	else
	{
		pd += n - 1;
		ps += n - 1;
		while (n--)
			*pd-- = *ps--;
	}
	return (dst);
}
