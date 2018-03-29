/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:37:36 by anlungu           #+#    #+#             */
/*   Updated: 2017/11/27 12:51:56 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char *pstring;
	char *pfind;
	char *begin;

	pstring = (char*)str;
	if (!*to_find)
		return (pstring);
	while (*pstring)
	{
		begin = (char*)pstring;
		pfind = (char*)to_find;
		while (*pfind == *begin && *pfind && *begin)
		{
			begin++;
			pfind++;
		}
		if (!*pfind)
			return (pstring);
		pstring++;
	}
	return (NULL);
}
