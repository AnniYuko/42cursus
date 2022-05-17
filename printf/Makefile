CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
NAMELFT := libft.a
sources :=  ft_printf.c
objects := $(sources:.c=.o)
LIBDIR := libft

all: $(NAME)

$(NAME): $(objects)
	make bonus -C $(LIBDIR)
	cp -v $(LIBDIR)/$(NAMELFT) $(NAME)
	ar cr $@ $^

$(objects): $(sources)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(objects)
	$(RM) *.o $(LIBDIR)/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
