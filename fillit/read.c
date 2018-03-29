/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocroitor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:51:25 by ocroitor          #+#    #+#             */
/*   Updated: 2017/12/27 15:27:29 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_read_min_max(char *str, t_point *min, t_point *max)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_tetris		*ft_read_get_piece(char *str, char value)
{
	t_point		*min;
	t_point		*max;
	char		**pos;
	int			i;
	t_tetris	*tetris;

	min = ft_tet_point_new(3, 3);
	max = ft_tet_point_new(0, 0);
	ft_read_min_max(str, min, max);
	pos = ft_memalloc(sizeof(char*) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5,\
				max->x - min->x + 1);
		i++;
	}
	tetris = ft_tet_tetris_new(pos, max->x - min->x + 1,\
			max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetris);
}

int				ft_read_check_connection(char *str)
{
	int			block;
	int			i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int				ft_read_check_counts(char *str, int count)
{
	int			i;
	int			blocks;

	i = 0;
	blocks = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count <= 21 && str[19] != '\n')
		return (4);
	if (!(ft_read_check_connection(str)))
		return (5);
	return (0);
}

t_list			*ft_read_read_tetris(int fd)
{
	char		*buf;
	char		onimirtet;
	int			count;
	t_list		*list;
	t_tetris	*tetris;

	buf = ft_strnew(21);
	list = NULL;
	onimirtet = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (ft_read_check_counts(buf, count) != 0 ||
				(tetris = ft_read_get_piece(buf, onimirtet++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (ft_tet_free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (ft_tet_free_list(list));
	ft_lstrev(&list);
	return (list);
}
