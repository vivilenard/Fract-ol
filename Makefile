# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:04:49 by vlenard           #+#    #+#              #
#    Updated: 2022/12/20 17:25:18 by vlenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
MLX = MLX42/libmlx42.a -I include -lglfw -L "/Users/vlenard/.brew/opt/glfw/lib/"
SRC = init.c draw.c colors.c hooks.c
OBJS = $(SRC:.c=.o)
NAME = fractol

all: $(LIBFT) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) && ./fractol
$(LIBFT): 
		cd libft && make && make clean
n:
		norminette $(SRC)
clean :
		rm -f $(OBJS)
fclean : clean
		rm -f ./$(NAME)
re : fclean
		$(MAKE) all