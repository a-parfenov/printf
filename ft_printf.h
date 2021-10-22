/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 04:10:17 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/22 04:10:42 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct all_s
{
	va_list	argc;
	int		i;
	int		count;
	char	tmp_str;
}			t_all;

typedef unsigned int	t_un_int;
# define HEX_L			"0123456789abcdef"
# define HEX_U			"0123456789ABCDEF"

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *str);

#endif