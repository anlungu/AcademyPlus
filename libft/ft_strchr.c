/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:54:25 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/02 11:24:11 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*pstring;

	pstring = (char*)str;
	while (*pstring)
	{
		if (*pstring == c)
			return (pstring);
		pstring++;
	}
	if (c == '\0')
		return (pstring);
	return (NULL);
}
