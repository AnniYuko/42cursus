CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
NAMELFT := libft.a
sources :=  ft_printf.c ft_printf_utils.c
objects := $(sources:.c=.o)
LIBDIR := libft

all: $(NAME)

$(NAME): $(objects)
	make bonus -C $(LIBDIR)
	cp -v $(LIBDIR)/$(NAMELFT) $(NAME)
	ar cr $@ $^
# cp -v (verbose = explain what is being dong)

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(objects)
	$(RM) *.o $(LIBDIR)/*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBDIR)/$(NAMELFT)

re: fclean all
.PHONY: all clean fclean re
