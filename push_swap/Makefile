# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 16:44:19 by akroll            #+#    #+#              #
#    Updated: 2022/10/13 14:57:38 by akroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f
CFLAGS := -Wall -Werror -Wextra

LFT_DIR := libft
LFT := $(LFT_DIR)/libft.a
HEADERS := -I $(LFT_DIR)
LIBS := -lft -L $(LFT_DIR)

NAME := push_swap
SRCS := main.c init.c error.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(HEADERS) $(LIBS)

$(OBJS): %.o: %.c $(LFT)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(LFT):
	make -C $(LFT_DIR)

clean:
	make clean -C $(LFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LFT)

re: fclean all
.PHONY: all clean fclean re
