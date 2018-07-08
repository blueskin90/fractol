# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 16:37:55 by toliver           #+#    #+#              #
#    Updated: 2018/03/19 22:44:32 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES =	main.c \
		putline.c \
		colorgradient.c \
		colorconversion.c \
		colorconversion2.c \
		gradientbar.c \
		button.c \
		buttonhold.c \
		init.c \
		init2.c \
		init3.c \
		img.c \
		complex.c \
		complexoperation.c \
		coord.c \
		buddhabrot.c \
		buddhabrot2.c \
		keyboard.c \
		mouse.c \
		julia.c \
		mandelbrot.c \
		burningship.c \
		multibrot.c \
		glynn.c \
		mandeldrop.c \
		mandelheart.c \
		menu.c \
		utility.c \
		printashapes.c \
		printshapes.c \
		printpreset.c \
		printpreset2.c \
		printcircle.c \
		rainbow.c \
		screen.c \
		colorlist.c \
		rgbpicker.c \
		thread.c \
		thread2.c \

OBJ = $(FILES:.c=.o)

INCLUDES = -I. -I./libft/includes -I./minilibx_macos

LIBFT = libft/libft.a

LIBX = minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto

MLX = -framework OpenGL -framework AppKit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) fractol.h
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(MLX) $(LIBFT) $(LIBX) $(INCLUDES)

%.o: %.c fractol.h
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	make clean -C minilibx_macos/
	rm -rf $(NAME)

re: fclean all
