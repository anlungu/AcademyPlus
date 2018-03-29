/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:56:47 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/01 18:28:04 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*ret;

	len = 0;
	while (src[len])
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (src[len])
	{
		ret[len] = src[len];
		len++;
	}
	ret[len] = '\0';
	return (ret);
}
