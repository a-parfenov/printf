#include <stdio.h>

#define hex_l "0123456789abcdef"
#define hex_u "0123456789ABCDEF"

int fd_main(size_t num, size_t base, char *alfabet)
{
	int	index[100];
	int	i;
	int	tmp;

	if (!alfabet || strlen(alfabet) < base)
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

typedef struct color_s
{
	double	r;
	double	g;
	double	b;
}				color_t;


color_t	color_slider(color_t start, color_t end, size_t range, size_t value_in_range)
{
	color_t	tmp;

	start.r = start.r + (end.r - start.r) / range * value_in_range;
	start.g = start.g + (end.g - start.g) / range * value_in_range;
	start.b = start.b + (end.b - start.b) / range * value_in_range;
	return (start);
}

int	main(int argc, char const *argv[])
{
	// fd_main(0, 12, hex_l);
	// printf("\n");
	// fd_main(13, 12, hex_l);
	// printf("\n");
	// fd_main(120, 12, hex_l);
	// printf("\n");
	color_t start;
	color_t end;
	color_t result;
	size_t	range = 30;

	start.r = 200;
	start.g = 200;
	start.b = 0;
	end.r = 0;
	end.g = 255;
	end.b = 255;
	for (size_t i = 0; i < range; i++)
	{
		result = color_slider(start, end, range, i);
		printf("\e[48;2;%i;%i;%im%21s\e[m\n", (int)result.r, (int)result.g, (int)result.b, " ");
	}
	return 0;
}
