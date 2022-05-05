/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:57:13 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/05 18:12:36 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ctostr(unsigned char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

static char	*ft_stostr(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_strdup(str));
}

char	*ft_conv(int chr, va_list ap)
{
	char			*res;
	unsigned char	c;

	c = (unsigned char)chr;
	if (c == 'c')
		res = ft_ctostr((unsigned char)va_arg(ap, int));
	if (c == 's')
		res = ft_stostr(ap);
	if (c == 'p')
		res = ft_ptoa((unsigned long long int)va_arg(ap, void *));
	if (c == 'd')
		res = ft_itoa(va_arg(ap, int));
	if (c == 'i')
		res = ft_itoa(va_arg(ap, int));
	if (c == 'u')
		res = ft_uitoa(va_arg(ap, unsigned int), c);
	if (c == 'x')
		res = ft_uitoa(va_arg(ap, unsigned int), c);
	if (c == 'X')
		res = ft_uitoa(va_arg(ap, unsigned int), c);
	return (res);
}
