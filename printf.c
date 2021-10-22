/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:00:44 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/22 04:09:53 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_xX(size_t num, size_t base, char *alfabet)
{
	int	index[100];
	int	i;
	int	tmp;

	if (!alfabet || ft_strlen(alfabet) < base)
		return (-1);
	index[0] = 0;
	i = num == 0;
	while (num)
	{
		index[i] = num % base;
		num /= base;
		++i;
	}
	tmp = i;
	while (i)
		write(1, &alfabet[index[--i]], 1);
	return (tmp);
}

static void	ft_check_s(t_all *all, char *s)
{
	if (s == NULL)
		all->count += write(1, "(null)", 6);
	else
		all->count += write(1, s, ft_strlen(s));
}

static int	ft_putnbr(ssize_t n, int count)
{
	char	c;

	if (!(n / 10 == 0))
		count = ft_putnbr((n / 10), count);
	count += write(1, "-", (n < 0 && (n / 10 == 0)));
	count += write(1, &c + 0 * (c = n % 10 * (1 - 2 * (n < 0)) + '0'), 1);
	return (count);
}

static void	ft_check_type(t_all *all, char *str)
{
	if (str[++all->i] == '%')
		all->count += write(1, "%", 1);
	else if (str[all->i] == 's')
		ft_check_s(all, va_arg(all->argc, void *));
	else if (str[all->i] == 'c')
	{
		all->tmp_str = va_arg(all->argc, int);
		all->count += write(1, &all->tmp_str, 1);
	}
	else if (str[all->i] == 'd' || str[all->i] == 'i')
		all->count += ft_putnbr(va_arg(all->argc, int), 0);
	else if (str[all->i] == 'u')
		all->count += ft_putnbr((t_un_int)va_arg(all->argc, int), 0);
	else if (str[all->i] == 'x')
		all->count += ft_printf_xX((t_un_int)va_arg(all->argc, int), 16, HEX_L);
	else if (str[all->i] == 'X')
		all->count += ft_printf_xX((t_un_int)va_arg(all->argc, int), 16, HEX_U);
	else if (str[all->i] == 'p')
	{
		all->count += write(1, "0x", 2);
		all->count += ft_printf_xX(va_arg(all->argc, long), 16, HEX_L);
	}
}

int	ft_printf(const char *str, ...)
{
	t_all	all;

	va_start(all.argc, str);
	all.i = -1;
	all.count = 0;
	while (str[++all.i])
	{
		if (str[all.i] == '%' && str[all.i + 1] != '\0')
			ft_check_type(&all, (char *)str);
		else
			all.count += write(1, &str[all.i], 1);
	}
	va_end(all.argc);
	return (all.count);
}
