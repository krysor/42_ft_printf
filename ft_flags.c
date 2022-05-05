/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/05 17:17:47 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isflag(const char *s, char flag, char conv);

char	*ft_hash(const char *s, char *old_str, char conv)
{
	char	*new_str;
	size_t	str_len;

	if (conv != 'p' && ((conv != 'x' && conv != 'X') || !ft_isflag(s, '#', conv)))
		return (old_str);
	str_len = ft_strlen(old_str);
	new_str = (char *)malloc(sizeof(char) * str_len + 3);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '0';
	if (conv == 'X')
		new_str[1] = conv;
	else
		new_str[1] = 'x';
	(void)ft_strlcpy(new_str + 2, old_str, str_len + 1);
	free(old_str);
	return (new_str);
}

static int	ft_isflag(const char *s, char flag, char conv)
{
	while (*s != conv)
	{
		if (*s == flag)
			return (1);
		s++;
	}
	return (0);
}

/*
//static of niet
int ft_isflag(const char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}
*/