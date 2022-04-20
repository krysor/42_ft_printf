/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/20 19:08:11 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static char	*ft_subst(char *str, char c1, char c2)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == c1 && p == 0)
		{
			str[i] = c2;
			p = 1;
		}
		else
			p = 0;
		i++;
	}
	return (str);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*str;
	char	**arr;

	str = ft_subst(ft_strdup(), '%', 127);
	arr = split(str);
	if (arr == 0)
		return (1);
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
*/
