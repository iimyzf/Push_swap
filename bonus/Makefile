# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 01:39:48 by yagnaou           #+#    #+#              #
#    Updated: 2022/04/16 01:49:42 by yagnaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = *.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all