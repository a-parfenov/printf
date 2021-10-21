/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:00:44 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/21 17:40:55 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_printf_x(unsigned long nbr)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(nbr, 16);
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_strlen(str));
}

static int ft_printf_X(unsigned long nbr)
{
	char	*str;
	int		i;
	
	i = 0;
	str = ft_itoa(nbr, 16);
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
		++i;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_strlen(str));
}

static int ft_printf_p(unsigned long long nbr)
{
	char	*str;
	int		i;
	
	i = 0;
	str = ft_itoa(nbr, 16);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_strlen(str) + 2);
}

int ft_printf(const char *str, ...)
{
	va_list	argc;
	int		i;
	int		count;
	char	*tmp_str;
	va_start(argc, str);
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			++i;
			if (str[i] == '%')
				count += write(1, "%", 1);
			else if (str[i] == 's')
				count += ft_putstr_fd(va_arg(argc, char *), 1);
			else if (str[i] == 'c')
			{
				tmp_str = va_arg(argc, void *);
				count += ft_putchar_fd(*tmp_str, 1);
			}
			else if (str[i] == 'd' || str[i] == 'i')
				count += ft_putnbr_fd(va_arg(argc, int), 1);
			else if (str[i] == 'u')
				count += ft_putnbr_fd(va_arg(argc, unsigned int), 1);
			else if (str[i] == 'x')
				count += ft_printf_x(va_arg(argc, unsigned long));
			else if (str[i] == 'X')
				count += ft_printf_X(va_arg(argc, unsigned long));
			else if (str[i] == 'p')
				count += ft_printf_p(va_arg(argc, unsigned long long));
		}
		else
			count += write(1, &str[i], 1);
		++i;
	}
	va_end(argc);
	return (count);
}
