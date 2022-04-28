/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:29:37 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/28 18:32:03 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_isflag(const char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_mod(const char *s, ...)
{
	va_list	ap;
	int		field;
	int		prec;
	int		i;
	char	*res;

	i = 0;
	while (ft_isflag(s[i]))
		i++;
	field = ft_atoi(s + i);
	while (ft_isdigit(s[i++]))
	prec = ft_atoi(s + i);
	while (ft_isdigit(s[i++]))
	if (ft_isconv(s[i]))
		return (); 
	
	char *conv = ft_conv(, );
	(void)s;
	write (1, "Z", 1);
	return (ft_printf(s + 1, ap));
}
