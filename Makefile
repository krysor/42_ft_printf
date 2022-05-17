# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:04:19 by kkaczoro          #+#    #+#              #
#    Updated: 2022/05/17 18:32:19 by kkaczoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSa	= ft_conv.c ft_ptoa.c ft_uitoa.c ft_flags.c ft_dot.c ft_field.c

SRCS	= ${SRCSa} ft_printf.c 

BONS	= ${SRCSa} ft_printfb.c

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BONS:.c=.o}

NAME	= libftprintf.a

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			$(MAKE) -C libft
			cp libft/libft.a ${NAME}
			ar r ${NAME} ${OBJS}

all:		${NAME}

bonus:		${BOBJS}
			$(MAKE) -C libft
			cp libft/libft.a ${NAME}
			@ar r ${NAME} ${BOBJS}
			@echo "relinking bonus finished"

clean:
			${RM} ${OBJS} ${BOBJS}
			$(MAKE) clean -C libft

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re