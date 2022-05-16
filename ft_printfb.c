/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/16 15:59:16 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_printf_real(const char *s, va_list ap);
static int		ft_modif(const char *s, va_list ap);
static int		ft_findconv(const char *s);
static size_t	ft_strlen_zero(const char *s);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		result;

	if (s == NULL || *s == '\0')
		return (0);
	va_start(ap, s);
	result = ft_printf_real(s, ap);
	va_end(ap);
	return (result);
}

static int	ft_printf_real(const char *s, va_list ap)
{
	if (*s == '\0')
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
	int		zero_c;

	i_conv = ft_findconv(s);
	if (i_conv == -1)
		return (0);
	str = ft_conv(s[i_conv], ap);
	zero_c = 0;
	if (str != NULL && s[i_conv] == 'c' && (int)ft_strlen(str) == 0)
		zero_c = 1;
	str = ft_flag(s, str, i_conv);
	if (str == NULL)
		return (0);
	result = ft_strlen(str);
	if (zero_c)
	{
		result = ft_strlen_zero(str);
		write(1, str, result);
	}
	else
		ft_putstr_fd(str, 1);
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

static size_t	ft_strlen_zero(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	i++;
	while (s[i])
		i++;
	return (i);
}

/*
static int	ft_modif(const char *s, va_list ap)
{
	int		result;
	int		i_conv;
	char	*str;
	int		zero_c;

	i_conv = ft_findconv(s);
	if (i_conv == -1)
		return (0);
	str = ft_conv(s[i_conv], ap);
	if (str == NULL)
		return (0);//cant remove this NULL protection CAUSE next if needs ft_strlen
	zero_c = 0;
	if (s[i_conv] == 'c' && (int)ft_strlen(str) == 0)
		zero_c = 1;
	str = ft_flag(s, str, i_conv);
	if (str == NULL)
		return (0);
	result = ft_strlen(str);
	if (zero_c)
	{
		result = ft_strlen_zero(str);
		write(1, str, result);
	}
	else
		ft_putstr_fd(str, 1);
	result += ft_printf_real(s + i_conv + 1, ap);
	free(str);
	return (result);
}
*/

/*
static int	ft_modif(const char *s, va_list ap)
{
	int		result;
	int		i_conv;
	char	*str;
	int		zero_c;

	i_conv = ft_findconv(s);
	if (i_conv == -1)
		return (0);
	str = ft_conv(s[i_conv], ap);
	if (str == NULL)
		return (0);
	zero_c = 0;
	if (s[i_conv] == 'c' && (int)ft_strlen(str) == 0)
		zero_c = 1;
	str = ft_flag(s, str, i_conv);
	if (str == NULL)
		return (0);
	result = ft_strlen(str);
	if (zero_c)
	{
		result = ft_strlen_zero(str);
		write(1, str, result);
	}
	else
		ft_putstr_fd(str, 1);
	result += ft_printf_real(s + i_conv + 1, ap);
	free(str);
	return (result);
}
*/
