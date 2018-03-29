/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:22:57 by anlungu           #+#    #+#             */
/*   Updated: 2018/01/09 10:35:16 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		endline(char *buff)
{
	int			count;

	count = 0;
	while (buff[count] != '\n' && buff[count])
		count++;
	if (buff[count] == '\n')
	{
		buff[count] = '\0';
		return (count);
	}
	else
		return (-1);
}

static char		*join(char *buff, char *tab)
{
	size_t		i;
	size_t		j;
	char		*p;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	p = (char *)malloc(sizeof(*p) * (i + j + 1));
	ft_memcpy(p, buff, i);
	ft_memcpy(p + i, tab, j);
	p[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (p);
}

static int		verif(char **buff, char **tab, char **line)
{
	char		*p;
	int			final;

	*buff = join(*buff, *tab);
	final = endline(*buff);
	if (final > -1)
	{
		*line = ft_strdup(*buff);
		p = *buff;
		*buff = ft_strdup(*buff + final + 1);
		free(p);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff[BUFF_SIZE + 1];
	char		*tmp;
	int			result;
	int			ret;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		result = verif(&buff[fd], &tmp, line);
		free(tmp);
		if (result == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((result = verif(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (result);
}
