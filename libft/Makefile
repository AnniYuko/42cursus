CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
sources := $(wildcard *.c)
objects := $(sources:.c=.o)
#bonusdir := lists
#bonus_sources := $(wildcard $(bonusdir)/*.c) $(wildcard *.c)
#problem with folder here
#bonus_objects := $(bonus_sources:.c=.o)
NAME := libft.a

all: $(NAME)

$(NAME): $(objects)
	ar cr $@ $^

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# bonus: $(bonus_sources)
# 	$(CC) $(CFLAGS) -c $^
# 	ar cr $(NAME) $(bonus_objects)

clean:
	$(RM) $(objects)

fclean:
	$(RM) $(objects) $(NAME)

re: fclean all

.PHONY: all clean fclean re
