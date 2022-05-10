/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/10 11:37:59 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_sign(const char *s, char *old_str, int i_conv);
char	*ft_field(const char *s, char *old_str, int i_conv);

char	*ft_flag(const char *s, char *old_str, int i_conv)
{
	old_str = ft_dot(s, old_str, i_conv);//protect everything from NULL result?
	old_str = ft_hash(s, old_str, s[i_conv]);
	old_str = ft_sign(s, old_str, i_conv);//control sign AFTER making MFV work
	//old_str = ft_flags(s, old_str, i_conv);
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
	int		len_old;
	char	*new_str;

	space = ft_isflag(s, ' ', s[i_conv]);
	plus = ft_isflag(s, '+', s[i_conv]);
	len_old = ft_strlen(old_str);
	if ((s[i_conv] != 'i' && s[i_conv] != 'd') || old_str[0] == '-'
		|| (!space && !plus))
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * len_old + 2);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = ' ';
	if (plus)
		new_str[0] = '+';
	(void)ft_strlcpy(new_str + 1, old_str, len_old + 1);
	free(old_str);
	return (new_str);
}

char	*ft_field(const char *s, char *old_str, int i_conv)
{
	int		field;
	int		len_old;
	char	*new_str;

	while (*s == '-' || *s == '0' || *s == '#' || *s == ' ' || *s == '+')
		s++;
	new_str = (char *)ft_memchr((void *)s, '.', (size_t)i_conv);
	field = 0;
	if (new_str != 0)
		field = ft_atoi(new_str + 1);
	len_old = (int)ft_strlen(old_str);
	if (!field || field <= len_old)
		return (old_str);
	new_str = (char *)malloc(sizeof(char) * field + 1);
	if (new_str == NULL)
		return (NULL);
	
	free(old_str);
	return (new_str);
}
