/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/21 21:10:40 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static int	ft_nb_arg(char *s)
{
	int		nb;
	char	*convs;
	int		i;

	convs = "cspdiuxX%%";
	nb = 0;
	while (*s)
	{
		i = 0;
		while (convs[i])
		{
			if (*s == '%' && (*(s + 1) == convs[i]))
			{
				nb++;
				s++;
				break ;
			}
			i++;
		}
		s++;
	}
	return (nb);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		nb_arg;

	nb_arg = ft_nb_arg(s);
	va_start(ap, 0);

	va_end(ap);
	return (0);
}

/*
BLUEPRINT printf
1. parse the string
	1.1 c different than % -> write c
	1.2 c == %
		1.2.1 look at characterS after %
			1.2.1.1 if the character one of the flagLIST
				1.2.1.1.1 apply flag modifications
					1.2.1.1.1.1 create array or str of flag modifications
					1.2.1.1.1.2 create corresponding array or str of flag modifications FUNCTIONS
			1.2.1.2 if the character one of the convesionLIST
				1.2.1.2.1 apply conversion with proper function
					1.2.1.2.1.1 create array or str of conversion modifications
					1.2.1.2.1.2 create corresponding array or str of conversion FUNCTIONS
			1.2.1.3 write the standard characters

practical:
	1. split by "%"
		1.1 copy the original input str
		1.2 if last c isnt %
			1.2.1 replace % by SMTH ELSE
				127 = DEL
		1.3 use SMTH ELSE as split separator
			1.3.1 CHECK IF THERES AN ANOTHER ASCII CHARACTER LIKE "%" THAT HAS NO EFFECT IN PRINTF
	2. copy flags into temp char
	3. create new

TE DOEN
	1. check if ft arg nb for sure works correctly
*/

