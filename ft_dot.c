/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:19:09 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/09 16:12:49 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_dotornot(const char *s, char *old_str, int ind_conv, int *prec);
static void	ft_negative(char *new_str);

char	*ft_dot(const char *s, char *old_str, int ind_conv)
{
	const char	*new_str;
	int			precision;

	new_str = (char *)ft_memchr((void *)s, '.', (size_t)ind_conv);
	precision = 0;
	if (new_str != 0)
		precision = ft_atoi(new_str + 1);
	if (ft_dotornot(s, old_str, ind_conv, &precision))
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * precision + 1);
	if (new_str == NULL)
		return (NULL);
	if (s[ind_conv] != 's')
	{
		(void)ft_memset((void *)new_str, '0', precision - ft_strlen(old_str));
		(void)ft_strlcpy((char *)(new_str + precision - ft_strlen(old_str)),
			old_str, ft_strlen(old_str) + 1);
	}
	else
		(void)ft_strlcpy((char *)(new_str), old_str, precision + 1);
	if ((s[ind_conv] == 'd' || s[ind_conv] == 'i') && old_str[0] == '-')
		ft_negative((char *)new_str);
	free(old_str);
	return ((char *)new_str);
}

static int	ft_dotornot(const char *s, char *old_str, int ind_conv, int *prec)
{
	char	conv;

	conv = s[ind_conv];
	if ((!ft_isflag(s, '.', conv) || conv == 'c' || *prec < 0
			|| ((conv == 'd' || conv == 'i' || conv == 'o' || conv == 'u'
					|| conv == 'x' || conv == 'X')
				&& *prec <= (int)ft_strlen(old_str))
			|| (conv == 's' && *prec >= (int)ft_strlen(old_str))))
	{
		if ((conv == 'd' || conv == 'i') && old_str[0] == '-'
			&& *prec + 1 > (int)ft_strlen(old_str))
		{	
			(*prec)++;
			return (0);
		}
		return (1);
	}
	return (0);
}

static void	ft_negative(char *new_str)
{
	new_str[0] = '-';
	new_str++;
	while (*new_str != '-')
		new_str++;
	*new_str = '0';
}
