/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:46:25 by anlungu           #+#    #+#             */
/*   Updated: 2017/11/30 15:22:58 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s || !(new = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (*((s + start) + ++i) && i < len)
		*(new + i) = *((s + start) + i);
	*(new + i) = '\0';
	return (new);
}
