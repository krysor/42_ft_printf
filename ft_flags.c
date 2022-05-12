/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/12 14:11:04 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_sign(const char *s, char *old_str, int i_conv);

char	*ft_flag(const char *s, char *old_str, int i_conv)
{
	if (old_str == NULL)
		return (NULL);
	old_str = ft_dot(s, old_str, i_conv);
	if (old_str == NULL)//old_str wont get free if failure
		return (NULL);
	old_str = ft_hash(s, old_str, i_conv);
	if (old_str == NULL)
		return (NULL);
	old_str = ft_sign(s, old_str, i_conv);//control sign AFTER making MFV work
	if (old_str == NULL)
		return (NULL);
	old_str = ft_field(s, old_str, i_conv);
	if (old_str == NULL)
		return (NULL);
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
