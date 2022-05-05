/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:19:39 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/05 18:12:00 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_charnb(unsigned int n, char c);
static void	ft_itoareal(unsigned int n, char *str, int len, char c);
static void	ft_strtoupper(char *str);

char	*ft_uitoa(unsigned int n, char c)
{
	int		nbchr;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	nbchr = ft_charnb(n, c);
	str = (char *)malloc(sizeof(char) * (nbchr + 1));
	if (str == NULL)
		return (NULL);
	str[nbchr] = '\0';
	ft_itoareal(n, str, nbchr, c);
	if (c == 'X')
		ft_strtoupper(str);
	return (str);
}

static int	ft_charnb(unsigned int n, char c)
{
	int				nb_char;
	unsigned int	divider;
	unsigned int	base;

	nb_char = 8;
	divider = 268435456;
	base = 16;
	if (c == 'u')
	{
		nb_char = 10;
		divider = 1000000000;
		base = 10;
	}
	while (n / divider == 0)
	{
		nb_char--;
		divider /= base;
	}
	return (nb_char);
}

static void	ft_itoareal(unsigned int n, char *str, int len, char c)
{
	int				i;
	unsigned int	base;
	char			*chars;

	i = len - 1;
	base = 16;
	chars = "0123456789abcdef";
	if (c == 'u')
		base = 10;
	while (n / base != 0)
	{
		str[i] = chars[n % base];
		i--;
		n /= base;
	}
	str[i] = chars[n % base];
}

static void	ft_strtoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
