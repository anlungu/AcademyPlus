/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:50:03 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/02 13:47:56 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ps;
	unsigned char *pd;
	unsigned char pc;

	if (n)
	{
		pc = (unsigned char)c;
		ps = (unsigned char*)src;
		pd = (unsigned char*)dst;
		while (n-- != 0)
			if ((*pd++ = *ps++) == pc)
				return (pd);
	}
	return (NULL);
}
