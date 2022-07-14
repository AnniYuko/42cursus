# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 09:28:51 by akroll            #+#    #+#              #
#    Updated: 2022/07/14 15:06:12 by akroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f
NAMELFT := libft.a
LIBDIR := libft
EXEC := client server
SRC := client.c server.c
OBJ := $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@ -L./$(LIBDIR) -lft

$(NAMELFT):
	make -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIBDIR)/$(NAMELFT) $(EXEC)

re: fclean all
.PHONY: all clean fclean re
