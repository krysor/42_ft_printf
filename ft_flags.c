/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/16 16:36:25 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_sign(const char *s, char *old_str, int i_conv);

char	*ft_flag(const char *s, char *old_str, int i_conv)
{
	if (old_str == NULL)
		return (NULL);
	old_str = ft_dot(s, old_str, i_conv);
	if (old_str == NULL)
		return (NULL);
	old_str = ft_hash(s, old_str, i_conv);
	if (old_str == NULL)
		return (NULL);
	old_str = ft_sign(s, old_str, i_conv);
	if (old_str == NULL)
		return (NULL);
	old_str = ft_field(s, old_str, i_conv);
	return (old_str);
}

int	ft_isflag(const char *s, char flag, int i_conv)
{
	int	i;

	i = 0;
	while (s[i] != s[i_conv] && ft_memchr("-0# +", s[i], 5))
	{
		if (s[i] == flag)
			return (1);
		i++;
	}
	if (flag == '.')
	{
		while (s[i] != s[i_conv])
		{
			if (s[i] == flag)
				return (1);
			i++;
		}
	}
	return (0);
}

static char	*ft_sign(const char *s, char *old_str, int i_conv)
{
	int		plus;
	int		space;
	int		len_old;
	char	*new_str;

	space = ft_isflag(s, ' ', i_conv);
	plus = ft_isflag(s, '+', i_conv);
	len_old = ft_strlen(old_str);
	if ((s[i_conv] != 'i' && s[i_conv] != 'd') || old_str[0] == '-'
		|| (!space && !plus))
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * len_old + 2);
	if (new_str == NULL)
	{
		free (old_str);
		return (NULL);
	}
	new_str[0] = ' ';
	if (plus)
		new_str[0] = '+';
	(void)ft_strlcpy(new_str + 1, old_str, len_old + 1);
	free(old_str);
	return (new_str);
}

char	*ft_hash(const char *s, char *old_str, int i_conv)
{
	char	*new_str;
	size_t	str_old;

	if (old_str == NULL)
		return (NULL);
	if ((s[i_conv] != 'p' && ((s[i_conv] != 'x' && s[i_conv] != 'X')
				|| !ft_isflag(s, '#', i_conv)))
		|| (s[i_conv] != 'p' && ft_strlen(old_str) == 1 && old_str[0] == '0'))
		return (old_str);
	str_old = ft_strlen(old_str);
	new_str = (char *)malloc(sizeof(char) * str_old + 3);
	if (new_str == NULL)
	{
		free(old_str);
		return (NULL);
	}
	new_str[0] = '0';
	if (s[i_conv] == 'X')
		new_str[1] = s[i_conv];
	else
		new_str[1] = 'x';
	(void)ft_strlcpy(new_str + 2, old_str, str_old + 1);
	free(old_str);
	return (new_str);
}
