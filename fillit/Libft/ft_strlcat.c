/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:14:41 by anlungu           #+#    #+#             */
/*   Updated: 2017/11/27 12:50:36 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t slen;

	len = 0;
	slen = 0;
	while (src[slen])
		slen++;
	while (*dest && n > 0)
	{
		dest++;
		len++;
		n--;
	}
	while (*src && n > 1)
	{
		*dest++ = *src++;
		n--;
	}
	if (n == 1 || *src == 0)
		*dest = '\0';
	return (slen + len);
}
