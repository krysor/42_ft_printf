/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:12:14 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/12 14:17:02 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_hash(const char *s, char *old_str, int i_conv)
{
	char	*new_str;
	size_t	str_old;

	if ((s[i_conv] != 'p' && ((s[i_conv] != 'x' && s[i_conv] != 'X')
				|| !ft_isflag(s, '#', s[i_conv])))
		|| (s[i_conv] != 'p' && ft_strlen(old_str) == 1 && old_str[0] == '0'))
		return (old_str);
	str_old = ft_strlen(old_str);
	new_str = (char *)malloc(sizeof(char) * str_old + 3);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '0';
	if (s[i_conv] == 'X')
		new_str[1] = s[i_conv];
	else
		new_str[1] = 'x';
	(void)ft_strlcpy(new_str + 2, old_str, str_old + 1);
	free(old_str);
	return (new_str);
}
