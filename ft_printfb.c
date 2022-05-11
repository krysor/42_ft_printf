/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/11 13:42:49 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

static int	ft_printf_real(const char *s, va_list ap);
static int	ft_modif(const char *s, va_list ap);
static int	ft_findconv(const char *s);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, s);
	result = ft_printf_real(s, ap);
	va_end(ap);
	return (result);
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
	int		result;
	int		i_conv;
	char	*str;

	i_conv = ft_findconv(s);
	if (i_conv == -1)
		return (0);
	str = ft_flag(s, ft_conv(s[i_conv], ap), i_conv);
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	//ft_putchar_fd('Z', 1);//moet weg
	result = ft_strlen(str);
	//printf("result: %d\n", result);
	/*
	if (s[i_conv] == 'c' && result == 0)
	{
		result++;
		ft_putchar_fd(0, 1);
	}
	*/
	result += ft_printf_real(s + i_conv + 1, ap);
	free(str);
	return (result);
}

static int	ft_findconv(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'p'
			|| s[i] == 'd' || s[i] == 'i' || s[i] == 'u'
			|| s[i] == 'x' || s[i] == 'X')
			return (i);
		i++;
	}
	return (-1);
}
