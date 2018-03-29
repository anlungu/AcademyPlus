/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:41:35 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/05 18:16:37 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_whitespaces(const char *s, int *i, int *j)
{
	while (IS_SPACE(*(s + *i)))
		(*i)++;
	while (IS_SPACE(*(s + *j)))
		(*j)--;
	if (*i || *j < (int)ft_strlen(s))
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	char	*new;
	int		k;
	int		new_size;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	if (!has_whitespaces((char*)s, &i, &j) || !ft_strlen(s))
		return ((char*)s);
	if (i >= (int)ft_strlen(s))
		new_size = 0;
	else
		new_size = j - i;
	if (!(new = ft_strnew(new_size + 1)))
		return (NULL);
	while (i <= j)
		*(new + k++) = *(s + i++);
	*(new + k) = '\0';
	return (new);
}
