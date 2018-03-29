/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:07:03 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/01 20:23:36 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s || !(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(new + i) = f(*(s + i));
	return (new);
}
