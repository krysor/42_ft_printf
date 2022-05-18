# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:04:19 by kkaczoro          #+#    #+#              #
#    Updated: 2022/05/18 15:18:18 by kkaczoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_conv.c ft_ptoa.c ft_uitoa.c ft_flags.c ft_dot.c ft_field.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			$(MAKE) -C libft
			cp libft/libft.a ${NAME}
			ar r ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}
			$(MAKE) clean -C libft

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re