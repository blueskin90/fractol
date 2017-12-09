# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 16:37:55 by toliver           #+#    #+#              #
#    Updated: 2017/12/08 15:28:28 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = main.c \
		putline.c \
		keyboard.c \
		sierpinsky.c \
		mandelbrot.c \

OBJ = $(FILES:.c=.o)

INCLUDES = -I. -I./libft/includes -I./minilibx_macos

LIBFT = libft/libft.a

LIBX = minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) fractol.h
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(MLX) $(LIBFT) $(LIBX) $(INCLUDES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
#	make clean -C libft/
#	make clean -C minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
#	make fclean -C libft/
#	make clean -C minilibx_macos/
	rm -rf $(NAME)

re: fclean all
