/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 19:18:22 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/01 19:06:47 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (*p1 && *p2)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	if ((*p1 && !*p2) || (!*p1 && *p2))
		return (*p1 - *p2);
	return (0);
}
