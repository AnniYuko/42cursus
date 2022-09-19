# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 10:29:30 by akroll            #+#    #+#              #
#    Updated: 2022/09/19 17:23:14 by akroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f
CFLAGS := -Wall -Werror -Wextra -O3

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIB_MLX_DIR := ../../MLX42
LIBMLX := $(LIB_MLX_DIR)/libmlx42.a
ALL_LIBS := $(LIBFT) $(LIBMLX)
HEADERS := -I $(LIB_MLX_DIR)/include/MLX42 -I $(LIBFT_DIR)
LIBS := -lglfw -lm -L /Users/akroll/.brew/opt/glfw/lib $(LIBMLX) $(LIBFT)

NAME := fractol
SRCS := main.c input.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(ALL_LIBS):
	make -C $(LIBFT_DIR)
	make -C $(LIB_MLX_DIR)

$(NAME): $(OBJS) $(ALL_LIBS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(HEADERS) $(LIBS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

# zoom: zoom.o
# 	$(CC) $(CFLAGS) $< -o $@ $(HEADERS) $(LIBS)

# zoom.o: zoom.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all
.PHONY: all clean fclean re libmlx
