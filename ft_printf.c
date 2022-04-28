/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/28 15:43:57 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
