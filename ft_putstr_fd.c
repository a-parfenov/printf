/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:10:14 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/21 17:17:49 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char const *s, int fd)
{
	if (s && fd)
	{
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (0);
}
