/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:38:10 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/30 13:48:13 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_charnb(int n)
{
	int				nb;
	unsigned int	div;

	nb = 10;
	div = 1000000000;
	while (n / div == 0)
	{
		nb--;
		div /= 10;
	}
	return (nb);
}

static void	ft_itoareal(unsigned int n, char *str, int len)
{
	int	i;

	i = len - 1;
	while (n / 10 != 0)
	{
		str[i] = n % 10 + '0';
		i--;
		n /= 10;
	}
	str[i] = n % 10 + '0';
}

char	*ft_uitoa(unsigned int n)
{
	int		nbchr;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	nbchr = ft_charnb(n);
	str = (char *)malloc(sizeof(char) * (nbchr + 1));
	if (str == NULL)
		return (NULL);
	str[nbchr] = '\0';
	ft_itoareal(n, str, nbchr);
	return (str);
}
