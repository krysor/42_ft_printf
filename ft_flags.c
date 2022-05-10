/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/10 10:56:27 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_sign(const char *s, char *old_str, int i_conv);

char	*ft_flag(const char *s, char *old_str, int i_conv)
{
	old_str = ft_dot(s, old_str, i_conv);//protect everything from NULL result
	old_str = ft_hash(s, old_str, s[i_conv]);
	old_str = ft_sign(s, old_str, i_conv);//control sign AFTER making MFV work
	return (old_str);
}

int	ft_isflag(const char *s, char flag, char conv)
{
	while (*s != conv)
	{
		if (*s == flag)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_sign(const char *s, char *old_str, int i_conv)
{
	int		plus;
	int		space;
	int		len_str;
	char	*new_str;

	space = ft_isflag(s, ' ', s[i_conv]);
	plus = ft_isflag(s, '+', s[i_conv]);
	len_str = ft_strlen(old_str);
	if ((s[i_conv] != 'i' && s[i_conv] != 'd') || old_str[0] == '-'
		|| (!space && !plus))
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * len_str + 2);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = ' ';
	if (plus)
		new_str[0] = '+';
	(void)ft_strlcpy(new_str + 1, old_str, len_str + 1);
	free(old_str);
	return (new_str);
}

/*
int	ft_isflag(const char *s, char flag, char conv)
{
	while (*s != conv)
	{
		if (*s == flag)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_sign(const char *s, char *old_str, int i_conv)
{
	int		plus;
	int		space;
	int		len_str;
	char	*new_str;

	space = ft_isflag(s, ' ', s[i_conv]);
	plus = ft_isflag(s, '+', s[i_conv]);
	len_str = ft_strlen(old_str);
	if (s[i_conv] == 's' && len_str == 0 && space)
	{
		new_str = (char *)malloc(sizeof(char) * 2);
		if (new_str == NULL)
			return (NULL);
		new_str[0] = ' ';
		return (new_str);
	}
	if ((s[i_conv] != 'i' && s[i_conv] != 'd') || old_str[0] == '-'
		|| (!space && !plus))
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * len_str + 2);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = ' ';
	if (plus)
		new_str[0] = '+';
	(void)ft_strlcpy(new_str + 1, old_str, len_str + 1);
	free(old_str);
	return (new_str);
}
*/