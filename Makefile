# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:04:49 by vlenard           #+#    #+#              #
#    Updated: 2022/12/09 10:56:21 by vlenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = play.c
OBJS = $(SRC:.c=.o)
NAME = fractol.a

all: $(NAME) 
$(NAME) : $(OBJS) 
		ar rcs $(NAME) $(OBJS) 
m: all
		$(CC) $(NAME) MLX42/libmlx42.a -I include -lglfw -L "/Users/vlenard/.brew/opt/glfw/lib/" && ./a.out
n:
		norminette $(SRC)
clean :
		rm -f $(OBJS) ./a.out
fclean : clean
		rm -f $(NAME)
re : fclean
		$(MAKE) all