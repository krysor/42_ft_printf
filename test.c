/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/29 15:27:31 by kkaczoro         ###   ########.fr       */
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
	//int a = 456123;
	//void	*b = &a;
	char *str = "asdfzxc";
	printf("\n%d", printf("abc%.20hhzq", str));
	return (0);
}
*/

int	ft_modif(const char *s, ...)
{
	va_list	ap;
	int		i;
	char	c;
	int		res;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd'
			|| s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			c = s[i];
		i++;
	}
	if (c == 0)
		return (0);
	va_start(ap, s);
	res = 100;
	//res = ft_strlen(ft_conv(c, ap)) + ft_printf(s + i, ap); //fill with modficiation functions
	//possibly need to copy ap in the ft_conv call as not sure if the arg switch inside ft_conv remains in the call of ft_printf
	va_end(ap);
	return (res);
}
int	ft_printf(const char *s, ...)
{
	va_list	ap;

	if (s == NULL || *s == '\0')
		return (0);
	if (*s == '%')
	{
		if (*(s + 1) == '%')
		{
			write (1, "%%", 1);
			return (1 + ft_printf(s + 2, ap));
		}
		return (ft_modif(s + 1, ap));
	}
	else
	{
		write (1, &(*s), 1);
		return (1 + ft_printf(s + 1, ap));
	}
}
int	main(void)
{
	printf("\n%d\n", ft_printf("abc%hzqd", "abcdef%%%"));
	return (0);
}
