/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:00:44 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/20 01:51:27 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list			argc;
	//char			*s;
	int	arg;
	int				i;
	char			*tmp_str;
	va_start(argc, str);
	
	//s = va_arg(argc, char*);
	//arg = va_arg(argc, unsigned int);
	if (ft_strchr(str, '%') == 0)
		{
			ft_putstr_fd(str, 1);
			return (0);
		}
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1 != '\0'])
		{
			++i;
			if (str[i] == '%')
				write(1, "%", 1);
			else if (str[i] == 's')
			{
				tmp_str = va_arg(argc, void *);
				ft_putstr_fd(tmp_str, 1);
			}
			else if (str[i] == 'c')
			{
				tmp_str = va_arg(argc, void *);
				ft_putchar_fd(*tmp_str, 1);
			}
			else if (str[i] == 'd')
			{
				arg = va_arg(argc, int);
				ft_putnbr_fd(ft_itoa(arg), 1);
			}


			
			
			else
				write(1, &str[i], 1);
		++i;
		}
	}
	//ft_putnbr_fd(s, 1);

	//write(1, str, ft_strlen(s));
	//free(str);
	va_end(argc);
	return (0);
}
