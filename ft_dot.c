/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:19:09 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/09 12:25:18 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
