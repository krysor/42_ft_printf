/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/13 18:04:38 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

//te checken: c, s, p, d, i, u, x, X

int	main(void)
{
	//printf("%lu\n", ULONG_MAX);
	//const char *str = "%.10s";
	//printf("%s", ft_memchr(str, '.', (size_t)4));

	printf("%d\n", printf("abcdef\n"));
	printf("%d\n", ft_printf("abcdef\n"));

	return (0);
}
