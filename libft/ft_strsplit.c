/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:56:03 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/05 17:54:03 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static int	get_matrix_len(const char *s, char c)
{
	int i;
	int t;
	int size;

	i = 0;
	size = 0;
	t = get_word_len(s + i, c);
	while (s[i] != '\0' && t != 0)
	{
		while (s[i] == c)
			i++;
		i += t;
		size++;
		t = get_word_len(s + i, c);
	}
	return (size);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**new;
	int		ms;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	ms = get_matrix_len(s, c);
	if (!(new = (char**)malloc(sizeof(char*) * (ms + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ms)
	{
		k = 0;
		new[i] = ft_strnew(get_word_len(s + j, c));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			new[i][k++] = s[j++];
		new[i][k] = '\0';
	}
	new[i] = 0;
	return (new);
}
