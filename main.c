#include "ft_printf.h"
#include <limits.h>
int main(void)
{
	//printf("%s", "toto");
	//ft_printf("asd%c %s%d%u", "7", "rrr", 65, 2147483648);
	// printf("[%10.2s]\n", "toto");
    // ft_printf("[%10.2s]\n", "toto");
    // printf("Magic [%s] is [%10.5d]\n", "number", -42);
    // ft_printf("Magic [%s] is [%10.5d]\n", "number", -42);
	int x = 15155;
	int x1 = 15155;
	int b = printf("Hexadecimal for [%d] is [%x] [%X] [%p]\n", -42, x, x, x);
	int c = ft_printf("Hexadecimal for [%d] is [%x] [%X] [%p]\n", -42, x1, x1, x1);
	
	printf("%d %d\n", b, c);
	printf(" %c \n", '0');
	printf(" [%s] \n", NULL);
	ft_printf(" [%s] \n", NULL);

	printf("4 strings ------------------------\n");
	printf(" %p \n", -1);
	ft_printf(" %p \n\n", -1);
	printf(" %p \n", LONG_MIN);
	ft_printf(" %p \n\n", LONG_MIN);
	printf(" %p \n", INT_MAX);
	ft_printf(" %p \n", INT_MAX);
	
	
	// char *str = "lkjashdf";
	// printf(" %x \n", 0xFFFFFFFF + 1);
	// printf(" %p \n", 0xFFFFFFFFFFFFFFFF);
	//ft_printf(" %c ", '0');

	return 0;
}

/*
gcc main.c libftprintf.a && ./a.out
*/
	// if (ft_strchr(str, '%') == 0)
	// 	{
	// 		ft_putstr_fd(str, 1);
	// 		return (0);
	// 	}107ee0f85