# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:40:39 by cschulle          #+#    #+#              #
#    Updated: 2019/06/06 19:02:56 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
YLW := \033[38;5;214m
BLUE = \033[38;5;38m
RST := \033[0m 
SRCS = ft_memset.c	\
	ft_bzero.c		\
	ft_memcpy.c		\
	ft_memccpy.c 	\
	ft_memmove.c	\
	ft_memchr.c		\
	ft_memcmp.c 	\
	ft_strlen.c 	\
	ft_strdup.c		\
	ft_strcpy.c 	\
	ft_strncpy.c 	\
	ft_strcat.c		\
	ft_strlcat.c	\
	ft_strncat.c	\
	ft_strchr.c		\
	ft_strnchr.c	\
	ft_strrchr.c	\
	ft_strstr.c		\
	ft_strnstr.c	\
	ft_strcmp.c		\
	ft_strncmp.c	\
	ft_atoi.c		\
	ft_atoibase.c	\
	ft_isalpha.c	\
	ft_isdigit.c	\
	ft_ishexdigit.c	\
	ft_isalnum.c	\
	ft_isascii.c	\
	ft_isprint.c	\
	ft_isupper.c	\
	ft_islower.c	\
	ft_toupper.c	\
	ft_tolower.c	\
	ft_memalloc.c	\
	ft_memdel.c		\
	scoot.c			\
	ft_strnew.c		\
	ft_strdel.c		\
	ft_strclr.c		\
	ft_striter.c	\
	ft_striteri.c	\
	ft_strmap.c		\
	ft_strmapi.c	\
	ft_strequ.c		\
	ft_strnequ.c	\
	ft_strsub.c		\
	ft_strjoin.c	\
	ft_strjoinfree.c\
	ft_strtrim.c	\
	ft_strsplit.c	\
	ft_itoa.c		\
	ft_putchar.c	\
	ft_putstr.c		\
	ft_putendl.c	\
	ft_putnbr.c		\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_lstnew.c		\
	ft_lstdelone.c	\
	ft_lstdel.c		\
	ft_lstadd.c		\
	ft_lstiter.c	\
	ft_lstmap.c		\
	ft_numlen.c		\
	ft_putlist.c	\
	ft_putnode.c	\
	ft_putarray.c	\
	ft_wordcount.c	\
	ft_strcjoin.c	\
	ft_round.c		\
	ft_base.c 		\
	get_next_line.c	\
	ft_iswhitespace.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : 
	@gcc -c -Wall -Wextra -Werror $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(YLW)<< library created >>$(RST)"

clean : 
	@rm -f $(OBJS)
	@echo "$(YLW)<< object files cleaned >>$(RST)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(YLW)<< library cleaned >>$(RST)"	

testclean : fclean
	@rm -f test
	@echo "$(YLW)<< test files cleaned >>$(RST)"

re : fclean all
	@echo "$(YLW)<< library rebuilt >>$(RST)"

test : re
	@gcc -L. libft.a -o test main.c
	@echo "$(YLW)<< testfile compiled >>$(RST)"

LLDB : 
	@gcc -g *.c
	@echo "$(BLUE)<< debug generated >>$(RST)"
	# @lldb a.out
