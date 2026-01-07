
HEADERS = ./libftprintf.h
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
C = ft_itoa_u.c \
	ft_itoa.c \
	ft_printf_c.c \
	ft_printf_d.c \
	ft_printf_p.c \
	ft_printf_perc.c \
	ft_printf_s.c \
	ft_printf_u.c \
	ft_printf_x.c \
	ft_printf_X.c \
	ft_printf.c

$(NAME): 
	cc -c $(FLAGS) -I $(HEADERS) $(C)
	ar rcs $(NAME) $(C:.c=.o)

all: $(NAME)

clean:
	rm -f $(C:.c=.o) $(C_bonus:.c=.o)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
