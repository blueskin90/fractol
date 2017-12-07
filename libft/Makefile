# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 01:24:53 by toliver           #+#    #+#              #
#    Updated: 2017/11/18 14:36:44 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

FILES = atoi \
	   bzero \
	   isalnum \
	   isalpha \
	   isascii \
	   isdigit \
	   isprint \
	   itoa \
	   memalloc \
	   memccpy \
	   memchr \
	   memcmp \
	   memcpy \
	   memdel \
	   memmove \
	   memset \
	   putchar \
	   putchar_fd \
	   putendl \
	   putendl_fd \
	   putstr \
	   putstr_fd \
	   putnbr \
	   putnbr_fd \
	   strcat \
	   strchr \
	   strclr \
	   strcmp \
	   strcpy \
	   strdel \
	   strdup \
	   strequ \
	   striter \
	   striteri \
	   strjoin \
	   strlcat \
	   strlen \
	   strmap \
	   strmapi \
	   strncat \
	   strncmp \
	   strncpy \
	   strnequ \
	   strnew \
	   strnstr \
	   strrchr \
	   strsplit \
	   strstr \
	   strsub \
	   strtrim \
	   tolower \
	   toupper \
	   lstnew\
	   lstdelone \
	   lstdel \
	   lstadd \
	   lstiter \
	   lstmap \
	   get_next_line \

SRC = $(addprefix ft_,$(addsuffix .c,  $(FILES)))

SRC_PATH = srcs/

SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJS = $(SRC:.c=.o)

INCLUDES = -I./includes

HEADERS = libft.h


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: srcs/%.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
