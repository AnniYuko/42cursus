CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
sources := $(wildcard *.c)
objects := $(sources:.c=.o)
NAME := libft.a

all: $(NAME)

$(NAME): $(objects)
	ar cr $@ $^

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(objects)

fclean:
	$(RM) $(objects) $(NAME)

re: fclean all

.PHONY: all clean fclean re
