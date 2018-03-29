/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:32:56 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/05 18:02:18 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ps;
	unsigned char *pd;

	if (n)
	{
		ps = (unsigned char*)src;
		pd = (unsigned char*)dst;
		while (n > 0)
		{
			*pd++ = *ps++;
			n--;
		}
	}
	return (dst);
}
