/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:53:38 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/18 13:54:11 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_solve_solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetris	*tetris;

	if (list == NULL)
		return (1);
	y = 0;
	tetris = (t_tetris *)(list->content);
	while (y < map->size - tetris->height + 1)
	{
		x = 0;
		while (x < map->size - tetris->width + 1)
		{
			if (ft_map_place(tetris, map, x, y))
			{
				if (ft_solve_solve_map(map, list->next))
					return (1);
				else
					ft_map_set_piece(tetris, map, ft_tet_point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				ft_solve_roundup_sqrt(int n)
{
	int			i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

t_map			*ft_solve_solve(t_list *list)
{
	t_map		*map;
	int			size;

	size = ft_solve_roundup_sqrt(ft_lstcount(list) * 4);
	map = ft_map_map_new(size);
	while (!ft_solve_solve_map(map, list))
	{
		size++;
		ft_map_free_map(map);
		map = ft_map_map_new(size);
	}
	return (map);
}
