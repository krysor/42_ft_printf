/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:29:37 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/28 15:46:46 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
int ft_isconv(const char *s)
{
	if (s[i] != 'c' || s[i] != 's' || s[i] != 'p' || s[i] != 'd' || s[i] != 'i' || s[i] != 'u' || s[i] != 'x' || 
}
*/
int	ft_flag(const char *s, ...)
{
	va_list	ap;
	int		i;

	/*
	while ()
	char *conv = ft_conv(, );
	(void)s;
	*/
	write (1, "Z", 1);
	return (ft_printf(s + 1, ap));
}
