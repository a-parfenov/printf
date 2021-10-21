NAME	=	libftprintf.a

SRCS	=	printf.c	ft_putnbr_fd.c	ft_putstr_fd.c\
			ft_strlen.c	ft_strchr.c		ft_strdup.c\
			ft_strlcpy.c	ft_putchar_fd.c	ft_itoa.c

OBJ		=	$(SRCS:%.c=%.o)
HEADERS	=	ft_printf.h
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -I.$(HEADERS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(HEADERS)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all