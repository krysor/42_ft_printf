/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:57:13 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/26 15:45:27 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_conv(char c, ...)
{
	va_list	ap;
	char	*str;

	if (c == 'c')
		return ((char *)({, '\0'}));//missing
	if (c == 's')
		return (va_arg(ap, char *));
	if (c == 'p')
		return ();//missing hexa?
	if (c == 'd')
		return ();//missing deci?
	if (c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'u')
		return ();//missing deci?
	if (c == 'x')
		return ();//missing hexa?
	if (c == 'X')
		return ();//missing hexa?
	return (ft_printf(, ap));
}
