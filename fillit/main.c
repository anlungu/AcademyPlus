/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:33:51 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/27 15:14:44 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_success(int fd)
{
	char	buf[1024];
	int		success;
	int		i;

	i = 0;
	success = read(fd, buf, 1024);
	while (buf[i] != '\0')
		i++;
	if ((buf[i - 1] >= 0 && buf[i - 1] <= 31) &&
			(buf[i - 2] >= 0 && buf[i - 2] <= 31))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (ft_success(open(av[1], O_RDONLY)) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	if ((list = ft_read_read_tetris(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = ft_solve_solve(list);
	ft_map_print_map(map);
	ft_map_free_map(map);
	ft_tet_free_list(list);
	return (0);
}
