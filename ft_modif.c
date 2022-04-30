/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:29:37 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/30 20:41:53 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//static of niet
int	ft_isconv(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

/*
//static of niet
int ft_isflag(const char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}
*/


#include <stdio.h>
int	ft_modif(const char *s, va_list ap)
{
	//va_list	ap;
	int		i;
	char	c;
	int		res;
	char	*str;

	va_start(ap, s);
	printf("%c", (unsigned char)va_arg(ap, int));
	va_end(ap);
	i = 0;
	c = 0;
	while (s[i])
	{
		if (ft_isconv(s[i]))
			c = s[i];
		i++;
	}
	if (c == 0)
		return (0);
	//va_start(ap, s);
	str = ft_conv(c, ap);
	if (str == NULL)
		return (0);
	res = ft_strlen(str) + ft_printf(s + i, ap); //fill with modficiation functions
	//possibly need to copy ap in the ft_conv call as not sure if the arg switch inside ft_conv remains in the call of ft_printf
	free(str);
	//va_end(ap);
	return (res);
}
