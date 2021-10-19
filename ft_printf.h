#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

int ft_printf(const char *s, ...);

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);

#endif