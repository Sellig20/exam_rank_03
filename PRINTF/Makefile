# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 19:22:50 by jecolmou          #+#    #+#              #
#    Updated: 2022/07/11 14:28:36 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	srcs/ft_printf.c \
				srcs/ft_libft.c \
				srcs/ft_print_all.c \
				srcs/ft_bases.c \

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar -rcs	${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
