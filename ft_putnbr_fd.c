/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:10:09 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/21 18:00:04 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fd_main(int n, int fd, int count)
{
	char	c;

	if (n < 0)
		n = -n;
	if (n > 9)
	{
		fd_main(n / 10, fd, count);
		n = n % 10;
	}
	c = n + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		count++;
	}
	count += fd_main(n, fd, count);
	return (count);
}
