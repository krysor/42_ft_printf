/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:48:29 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/29 18:36:58 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:38:10 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/29 17:36:07 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charnb(unsigned long long int n)
{
	int						nb;
	unsigned long long int	div;

	nb = 12;
	div = 17592186044416;
	while (n / div == 0)
	{
		nb--;
		div /= 16;
	}
	return (nb);
}

//finish this one
static void	ft_itoareal(unsigned long long int n, char *str, int len)
{
	int	i;

	i = len - 1;
	while (n / 16 != 0)
	{
		str[i] = n % 16 + '0';
		i--;
		n /= 16;
	}
	str[i] = n % 16 + '0';
}

char	*ft_itoax(unsigned long long int n, char c)
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