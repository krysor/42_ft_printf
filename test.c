/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/04 16:03:13 by kkaczoro         ###   ########.fr       */
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
	//char a = 'z';
	//char *b = &a;
	//printf("%d\n", printf("%c\n", 'z'));
	//write(1, NULL, 1);
	printf("%d\n", printf("%lx\n", LONG_MAX));
	printf("%d\n", ft_printf("%x\n", LONG_MAX));
	//char *str = ft_strdup(NULL);
	//(void)str;
	return (0);
}
