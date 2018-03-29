/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlungu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:34:57 by anlungu           #+#    #+#             */
/*   Updated: 2017/11/27 12:53:02 by anlungu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	c;
	long			a;

	a = n;
	if (a < 0)
	{
		a *= -1;
		write(fd, "-", 1);
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putnbr_fd(a % 10, fd);
	}
	if (a < 10 && a >= 0)
	{
		c = (unsigned char)a + '0';
		write(fd, &c, 1);
	}
}
