# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:04:19 by kkaczoro          #+#    #+#              #
#    Updated: 2022/05/16 16:08:30 by kkaczoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSl	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS1	= $(addprefix libft/,${SRCSl})

SRCSa	= ft_conv.c ft_ptoa.c ft_uitoa.c ft_flags.c ft_dot.c ft_field.c

SRCS2	= ${SRCSa} ft_printf.c 

BONS	= ${SRCS1} ${SRCSa} ft_printfb.c

OBJS	= ${SRCS1:.c=.o} ${SRCS2:.c=.o}

BOBJS	= ${BONS:.c=.o}

NAME	= libftprintf.a

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar r ${NAME} ${OBJS}	

all:		${NAME}

bonus:		${BOBJS}
			@ar r ${NAME} ${BOBJS}
			@echo "relinking bonus finished"

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re