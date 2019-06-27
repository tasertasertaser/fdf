# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:40:39 by cschulle          #+#    #+#              #
#    Updated: 2019/06/26 21:04:01 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRCS	=	srcs/main.c			\
			srcs/file_parser.c	\
			srcs/colors.c		\
			srcs/valid.c		\
			srcs/frees.c		\
			srcs/lines.c		\
			srcs/draw.c			\
			srcs/grids.c		\
			srcs/testing.c		\
			srcs/keys.c			\
			srcs/error.c
INCLS	=	includes/fdf.h
WFLAGS	=	-Wall -Wextra -Werror
MLXFLAGS=	-framework OpenGL -framework AppKit
LIBS	=	-L libft -lft -L mlx -L mlx -lmlx

GREY = \033[38;5;6m
BLUE = \033[38;5;37m
WHITE = \033[0m 

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : 
	@gcc  -o $(NAME) $(WFLAGS) $(MLXFLAGS) $(LIBS) $(SRCS)
	@echo "$(GREY)<< executable built >>$(WHITE)"

clean : 
	@rm -f $(OBJS)
	@echo "$(GREY)<< object files removed >>$(WHITE)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(GREY)<< executable removed >>$(WHITE)"	

testclean : fclean
	@rm -f test main.c
	@echo "$(GREY)<< test files removed >>$(WHITE)"

re : fclean all

test : re
	# needs to be updated
	@gcc -L. libft.a -o test main.c
	@echo "$(GREY)<< testfile compiled >>$(WHITE)"

debug : 
	@gcc -fsanitize=address -g $(MLXFLAGS) $(SRCS) $(LIBS) -o DEBUGfdf
	@echo "$(BLUE)<< debug symbols compiled >>$(WHITE)"
