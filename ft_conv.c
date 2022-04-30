/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:57:13 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/30 16:42:38 by kkaczoro         ###   ########.fr       */
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
	char	*res;

	va_start(ap, c);
	if (c == 'c')
		res = ft_ctostr(va_arg(ap, char));
	if (c == 's')
		res = ft_strdup(va_arg(ap, char *));
	if (c == 'p')
		res = ft_itoax(va_arg(ap, unsigned long long int), 'x');
	if (c == 'd')
		res = ft_itoa(va_arg(ap, int));
	if (c == 'i')
		res = ft_itoa(va_arg(ap, int));
	if (c == 'u')
		res = ft_uitoa(va_arg(ap, unsigned int));
	if (c == 'x')
		res = ft_itoax(va_arg(ap, unsigned long long int), c);
	if (c == 'X')
		res = ft_itoax(va_arg(ap, unsigned long long int), c);
	va_end(ap);
	return (res);
}
