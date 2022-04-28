/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/28 15:54:18 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *s, ...);
/*
int	main(void)
{
	//printf("%d", ft_printf("zxc\Uxc"));
	//unsigned int	i = 123456789;
	int a = 456123;
	void	*b = &a;
	//char *str = "asdfzxc";

	printf("%+-200.10d", a);
	return (0);
}
*/
int	ft_flag(const char *s, ...)
{
	va_list	ap;
	int		i;

	/*
	while ()
	char *conv = ft_conv(, );
	(void)s;
	*/
	write (1, "Z", 1);
	return (ft_printf(s, ap));
}
int	ft_printf(const char *s, ...)
{
	va_list	ap;

	if (*s == '\0')
		return (0);
	va_start(ap, s);
	if (*s == '%')
	{
		if (*(s + 1) == '%')
		{
			write (1, "%%", 1);
			return (1 + ft_printf(s + 2, ap));
		}
		return (ft_flag(s + 1, ap));
	}
	else
	{
		write (1, &(*s), 1);
		return (1 + ft_printf(s + 1, ap));
	}
	va_end(ap);
}
int	main(void)
{
	printf("\n%d\n", ft_printf("abcdef%%%"));
	return (0);
}
