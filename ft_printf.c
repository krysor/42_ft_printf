/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/14 13:39:41 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *smth, ...)
{
	va_list	ap;

	va_start(ap, 0);
	va_end(ap);
	return (0);
}

/*
BLUEPRINT printf
1. parse the string
	1.1 c different than % -> write c
	1.2 c == %
		1.2.1 look at first character after %
			1.2.1.1 if the character one of the flagLIST
2. process each element independently and return the outcome
*/
