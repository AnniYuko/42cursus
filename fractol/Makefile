# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 10:29:30 by akroll            #+#    #+#              #
#    Updated: 2022/07/05 11:46:21 by akroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f
CFLAGS := -Wall -Werror -Wextra

LIB_MLX_DIR := ../../MLX42
HEADERS := -I $(LIB_MLX_DIR)/include/MLX42
LIBS := -lglfw -L /Users/akroll/.brew/opt/glfw/lib $(LIB_MLX_DIR)/libmlx42.a

NAME := fractol
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

all: libmlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $< -o $@ $(HEADERS) $(LIBS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

libft:

libmlx:
	make -C $(LIB_MLX_DIR)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re libft libmlx
