# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschulle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:40:39 by cschulle          #+#    #+#              #
#    Updated: 2019/03/10 19:49:06 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRCS	=	tests.c			\
			srcs/lines.c	\
			srcs/gradient.c
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
	@gcc -g $(MLXFLAGS) $(SRCS) $(LIBS) -o DEBUGfdf
	@echo "$(BLUE)<< debug symbols compiled >>$(WHITE)"
	@echo "$(BLUE)<< running lldb ./DEBUGfdf >>$(WHITE)"
	@lldb DEBUGfdf
