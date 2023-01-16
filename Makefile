# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:04:49 by vlenard           #+#    #+#              #
#    Updated: 2023/01/16 14:32:40 by vlenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
MLX = MLX42/libmlx42.a -I include -lglfw -L "/Users/vlenard/.brew/opt/glfw/lib/"
SRC = main.c init.c draw.c colors.c hooks.c fractals.c
OBJS = $(SRC:.c=.o)
NAME = fractol

all: $(NAME)
$(NAME): relibft $(LIBFT) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
$(LIBFT): 
		cd libft && make && make clean
relibft:
		cd libft && make re && make clean
n:
		norminette $(SRC) fractal.h
1: all	
		./fractol Julia 0.28 0.008
2: all
		./fractol Julia -0.4 0.6
3: all
		./fractol Julia 0.45 0.1428
4: all
		./fractol Julia -0.79 -0.15
5: all	
		./fractol Julia -0.162 1.04
6: all	
		./fractol Julia -1.476 0
clean :
		rm -f $(OBJS)
fclean : clean
		rm -f ./$(NAME)
re : fclean
		$(MAKE)
.PHONY: all, n, clean, fclean, re, $(LIBFT), $(NAME)