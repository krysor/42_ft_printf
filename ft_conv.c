/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:57:13 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/29 15:47:29 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ctostr(char c)
{
	char	*str;

	str = " \0";
	str[0] = c;
	return (ft_strdup(str));
}

char	*ft_conv(char c, ...)
{
	va_list	ap;

	va_start(ap, c);
	if (c == 'c')
		return (ft_ctostr(va_arg(ap, char)));
	if (c == 's')
		return (ft_strdup(va_arg(ap, char *)));
	if (c == 'p')
		return ();//missing hexa?
	if (c == 'd')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'u')
		return (ft_itoau(va_arg(ap, unsigned int)));
	if (c == 'x')
		return ();//missing hexa?
	if (c == 'X')
		return ();//missing hexa?
	return (NULL);
}
