/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:49:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/26 14:50:24 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;

	if (*s == '\0')
		return (0);
	else if (*s == '%')
		return (ft_flag(s + 1, ap));
	else
	{
		write (1, &(*s), 1);
		return (1 + ft_printf(s + 1, ap));
	}
	va_end(ap);
}
