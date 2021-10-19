/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:10:43 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/19 17:05:32 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *) malloc((ft_strlen(s1) + 1) * sizeof(const char));
	if (!mem)
		return (0);
	ft_strlcpy(mem, s1, ft_strlen(s1) + 1);
	return (mem);
}
