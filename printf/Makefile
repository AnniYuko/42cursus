CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
sources :=  ft_printf.c

objects := $(sources:.c=.o)
LIBDIR := libft

all: $(NAME)

$(NAME): $(objects)
	ar cr $@ $^

$(objects): $(sources)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(objects)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
