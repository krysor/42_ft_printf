/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/10 17:36:29 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
//#include <stdarg.h>
#include <unistd.h>

/*
int	main(void)
{
	unsigned int *b = (unsigned int *)malloc(sizeof(int));
	b[0] = 3234456123;
	unsigned long long int c = (unsigned long long int)b;
	printf("%d\n", printf("%p\n", b));
	printf("%d\n", printf("%s\n", ft_itoax(c, 'x')));
	return (0);
}
*/

//te checken: c, s, p, d, i, u, x, X

int	main(void)
{
	//printf("%lu\n", ULONG_MAX);
	//const char *str = "%.10s";
	//printf("%s", ft_memchr(str, '.', (size_t)4));

	printf("%d\n", printf(" %04d ", 9));
	printf("%d\n", ft_printf(" %04d ", 9));
	return (0);
}
