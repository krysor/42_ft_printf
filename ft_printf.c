/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/02 14:51:26 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_real(const char *s, va_list ap);
static int	ft_modif(const char *s, va_list ap);
static int	ft_isconv(const char c);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, s);
	res = ft_printf_real(s, ap);
	va_end(ap);
	return (res);
}

static int	ft_printf_real(const char *s, va_list ap)
{
	if (s == NULL || *s == '\0')
		return (0);
	if (*s == '%')
	{
		if (*(s + 1) == '%')
		{
			write (1, "%%", 1);
			return (1 + ft_printf_real(s + 2, ap));
		}
		return (ft_modif(s + 1, ap));
	}
	else
	{
		write (1, &(*s), 1);
		return (1 + ft_printf_real(s + 1, ap));
	}
}

static int	ft_modif(const char *s, va_list ap)
{
	int		i;
	char	c;
	int		res;
	char	*str;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (ft_isconv(s[i]))
		{
			c = s[i];
			break ;
		}
		i++;
	}
	if (c == 0)
		return (0);
	str = ft_conv(c, ap);
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	res = ft_strlen(str) + ft_printf_real(s + i + 1, ap); //fill with modficiation functions
	//possibly need to copy ap in the ft_conv call as not sure if the arg switch inside ft_conv remains in the call of ft_printf
	free(str);
	return (res);
}

static int	ft_isconv(const char c)
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
