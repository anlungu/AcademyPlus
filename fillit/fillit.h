/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:17:16 by anlungu           #+#    #+#             */
/*   Updated: 2017/12/27 15:14:52 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "./Libft/libft.h"

typedef struct		s_tetris
{
	char			**pos;
	int				width;
	int				height;
	char			value;
}					t_tetris;

typedef struct		s_map
{
	char			**array;
	int				size;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				ft_read_min_max(char *str, t_point *min, t_point *max);
t_tetris			*ft_read_get_piece(char *str, char value);
int					ft_read_check_connection(char *str);
int					ft_read_check_counts(char *str, int count);
t_list				*ft_read_read_tetris(int fd);

void				ft_map_free_map(t_map *map);
void				ft_map_print_map(t_map *map);
t_map				*ft_map_map_new(int size);
int					ft_map_place(t_tetris *tetri, t_map *map, int x, int y);
void				ft_map_set_piece(t_tetris *tetri,\
							t_map *map, t_point *point, char c);

t_map				*ft_solve_solve(t_list *list);
int					ft_solve_roundup_sqrt(int n);
int					ft_solve_solve_map(t_map *map, t_list *list);

t_list				*ft_tet_free_list(t_list *list);
void				ft_tet_free_tetris(t_tetris *tetri);
t_tetris			*ft_tet_tetris_new(char **pos,\
							int width, int height, char value);
t_point				*ft_tet_point_new(int x, int y);
int					ft_success(int fd);

#endif
