/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:06:49 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/21 14:28:35 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static void	ft_main(char *str, unsigned int len_num, int flag, long int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = 0;
	}
	if (n / 10 < 0)
	{
		str[--len_num] = '0' - n % 10;
		n /= 10;
		n = (long int)n * -1;
	}
	while (n > 0)
	{
		str[--len_num] = n % 10 + '0';
		n /= 10;
	}
	if (flag)
	{
		str[0] = '-';
	}
}

static int	ft_len(size_t n)
{
	int	i;

	i = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long			n1;
	int				len;
	char			*str;
	int				flag;

	n1 = n;
	len = 0;
	flag = 0;
	if (n1 < 0)
	{
		flag = 1;
		n1 *= -1;
		++len;
	}
	len += ft_len(n1);
	str = malloc((len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_main(str, len, flag, n1);
	return (str);
}*/

char *ft_itoa(unsigned long nbr, int base)
{
	unsigned long temp_nbr = nbr;
	int len = 0;
	char *str = NULL;
	if (nbr == 0)
		len++;
	while (temp_nbr > 0)
	{
		temp_nbr /= base;
		len++;
	}
	str = malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}