/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/06 18:31:51 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isflag(const char *s, char flag, char conv);

char	*ft_hash(const char *s, char *old_str, char conv)
{
	char	*new_str;
	size_t	str_len;

	if ((conv != 'p' && ((conv != 'x' && conv != 'X')
				|| !ft_isflag(s, '#', conv)))
		|| (conv != 'p' && ft_strlen(old_str) == 1 && old_str[0] == '0'))
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

char	*ft_dot(const char *s, char *old_str, int ind_conv)
{
	const char	*new_str;
	int			precision;

	new_str = (char *)ft_memchr((void *)s, '.', (size_t)ind_conv);
	if (new_str != 0)
		precision = ft_atoi(new_str + 1);
	else
		precision = 0;
	if (!ft_isflag(s, '.', s[ind_conv]) || s[ind_conv] == 'c' || precision < 0
		|| ((s[ind_conv] == 'd' || s[ind_conv] == 'i' || s[ind_conv] == 'o'
				|| s[ind_conv] == 'u' || s[ind_conv] == 'x'
				|| s[ind_conv] == 'X') && precision <= (int)ft_strlen(old_str))
		|| (s[ind_conv] == 's' && precision >= (int)ft_strlen(old_str)))
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * precision + 1);
	if (new_str == NULL)
		return (NULL);
	if (s[ind_conv] != 's')
	{
		(void)ft_memset((void *)new_str, '0', precision - ft_strlen(old_str));
		precision -= ft_strlen(old_str);
		(void)ft_memmove((void *)(new_str + precision), old_str, ft_strlen(old_str));
	}
	else
		(void)ft_memmove((void *)new_str, old_str, precision);
	free(old_str);
	return ((char *)new_str);
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
