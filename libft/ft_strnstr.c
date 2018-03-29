/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:25:00 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/05 17:21:08 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	t;
	char	*pstring;
	char	*pfind;
	char	*begin;

	pstring = (char*)str;
	if (!*to_find)
		return (pstring);
	while (*pstring && n > 0)
	{
		begin = (char*)pstring;
		pfind = (char*)to_find;
		t = n;
		while (*pfind == *begin && *pfind && *begin && t > 0)
		{
			begin++;
			pfind++;
			t--;
		}
		if (!*pfind)
			return (pstring);
		pstring++;
		n--;
	}
	return (NULL);
}
