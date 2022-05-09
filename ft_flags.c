/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/09 12:21:11 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_flag(const char *s, char *old_str, int i_conv)
{
	old_str = ft_dot(s, old_str, i_conv);
	old_str = ft_hash(s, old_str, s[i_conv]);
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
