CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
sources := $(filter-out $(wildcard ft_lst*.c), $(wildcard *.c))
objects := $(sources:.c=.o)
bonus_sources := $(wildcard ft_lst*.c)
bonus_objects := $(bonus_sources:.c=.o)
NAME := libft.a

all: $(NAME)

$(NAME): $(objects)
	ar cr $@ $^

$(objects): $(sources)
	$(CC) $(CFLAGS) -c $^

bonus: $(bonus_objects) $(objects)
	ar cr $(NAME) $^

$(bonus_objects): $(bonus_sources)
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) *.o

fclean:
	$(RM) *.o $(NAME)

re: fclean all

.PHONY: all clean fclean re
