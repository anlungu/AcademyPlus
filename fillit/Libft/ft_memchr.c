/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:29:53 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/01 18:28:19 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;
	unsigned char pc;

	p = (unsigned char*)s;
	pc = (unsigned char)c;
	while (n)
	{
		if (*p == pc)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
