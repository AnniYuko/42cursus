# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 12:37:11 by akroll            #+#    #+#              #
#    Updated: 2022/06/22 17:23:21 by akroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f
NAMELFT := libft.a
LIBDIR := libft
NAME := pipex
SRC := main.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(LIBDIR)/*.o $(OBJ)

fclean: clean
	$(RM) $(LIBDIR)/$(NAMELFT) $(NAME)

re: fclean all
.PHONY: all clean fclean
