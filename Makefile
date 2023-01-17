# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:14:58 by evdos-sa          #+#    #+#              #
#    Updated: 2023/01/11 19:31:02 by evdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\
			utils.c\
			
OBJS = $(SRCS:.c=.o)

HEADER	=	ft_printf.h
CC = cc
CFLAGS	= 	-Wall -Wextra -Werror
NAME	=	libftprintf.a

all:	$(NAME)

$(NAME): $(OBJS) $(HEADER)
		ar rcs $@ $^

.c.o:	$(SRCS)
		cc $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY: all clean fclean re
