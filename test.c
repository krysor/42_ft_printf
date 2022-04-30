/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/30 16:41:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
//#include <stdarg.h>
//#include <unistd.h>

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

int	main(void)
{
	unsigned long long int *b = (unsigned long long int *)malloc(sizeof(unsigned long long));
	b[0] = 140547951953552;
	unsigned long long int c = (unsigned long long int)b;
	printf("%d\n", printf("%s\n", "7fd3dec00690"));
	printf("%d\n", printf("%s\n", ft_itoax(140547951953552, 'x')));
	return (0);
}