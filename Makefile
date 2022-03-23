CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := libft.a

all: libft.a

libft.a:
	ar

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re: fclean all
