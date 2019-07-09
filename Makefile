# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:40:39 by cschulle          #+#    #+#              #
#    Updated: 2019/07/06 02:02:35 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRCS	=	srcs/main.c			\
			srcs/file_parser.c	\
			srcs/colors.c		\
			srcs/valid.c		\
			srcs/frees.c		\
			srcs/lines.c		\
			srcs/grids.c		\
			srcs/projections.c	\
			srcs/testing.c		\
			srcs/movekeys.c		\
			srcs/keys.c			\
			srcs/images.c		\
			srcs/help.c			\
			srcs/connect.c		\
			srcs/gttdl.c		\
			srcs/error.c
INCLS	=	includes/fdf.h
WFLAGS	=	-Wall -Wextra
#-Werror
MLXFLAGS=	-framework OpenGL -framework AppKit
LIBS	=	-L libft -lft -L mlx -L mlx -lmlx

GREY = \033[38;5;6m
BLUE = \033[38;5;37m
PURPLE = \033[38;5;99m
YELLOW = \033[38;5;214m
GREEN = \033[38;5;121m
WHITE = \033[0m

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : 
	@echo "$(YELLOW)Libft:"
	@make -C ./libft/
	@echo "$(PURPLE)MLX:"
	@make -C ./mlx/
	@gcc  -o $(NAME) $(WFLAGS) $(MLXFLAGS) $(LIBS) $(SRCS)
	@echo "$(GREY)<< executable built >>$(WHITE)"

clean : 
	@rm -f $(OBJS)
	@echo "$(GREY)<< object files removed >>$(WHITE)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(GREY)<< executable removed >>$(WHITE)"	

re : fclean all

debug : 
	@gcc -g $(MLXFLAGS) $(SRCS) $(LIBS) -o DEBUGfdf
	@echo "$(PURPLE)<< debug symbols compiled >>$(WHITE)"

fdebug : 
	@gcc -fsanitize=address -g $(MLXFLAGS) $(SRCS) $(LIBS) -o fsan_fdf
	@echo "$(PURPLE)<< debug symbols compiled >>$(WHITE)"
	@echo "$(PURPLE)<< fsanitize enabled >>$(WHITE)"

leakcheck : 
	@clang -fsanitize=address -fno-omit-frame-pointer -g $(MLXFLAGS) $(SRCS) $(LIBS) -o leak_fdf
	@echo "$(GREEN)<< debug symbols compiled >>$(WHITE)"
	@echo "$(GREEN)<< fsanitize leak check enabled >>$(WHITE)"

debugclean :
	@rm -rf DEBUGfdf.dSYM
	@rm DEBUGfdf
	@rm -rf fsan_fdf.dSYM
	@rm fsan_fdf
	@rm -rf leak_fdf.dSYM
	@rm leak_fdf
	@echo "$(PURPLE)<< debug files removed>>$(WHITE)"
