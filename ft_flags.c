/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/04 16:01:54 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_ishash(const char *s, char conv)
{
	int	i;

	i = 0;
	while (s[i] != conv)
	{
		if (s[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_hash(const char *s, char *str, char conv)
{
	char	*new_str;
	size_t	str_len;

	if (conv != 'p' && ((conv != 'x' && conv != 'X') || !ft_ishash(s, conv)))
		return (str);
	str_len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * str_len + 3);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '0';
	if (conv == 'X')
		new_str[1] = conv;
	else
		new_str[1] = 'x';
	(void)ft_strlcpy(new_str + 2, str, str_len + 1);
	free(str);
	return (new_str);
}
