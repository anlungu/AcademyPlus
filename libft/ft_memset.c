/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:58:27 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/01 17:16:17 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *p;

	if (n <= 0)
		return (str);
	p = (unsigned char *)str;
	while (n--)
		*p++ = (unsigned char)c;
	return (str);
}
