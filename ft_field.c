/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:30:43 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/11 12:12:24 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

char	*ft_zero(const char *s, char *old_str, int i_conv, int field);

char	*ft_field(const char *s, char *old_str, int i_conv)
{
	int		field;
	int		len_old;
	char	*new_str;
	int		i;

	i = 0;
	while (s[i] == '-' || s[i] == '0' || s[i] == '#' || s[i] == ' ' || s[i] == '+')
		i++;
	field = ft_atoi(s + i);
	len_old = (int)ft_strlen(old_str);
	if (!field || field <= len_old)
		return (old_str);
	if (ft_isflag(s, '0', s[i_conv])
		&& !ft_isflag(s, '-', s[i_conv]))
		new_str = ft_zero(s, old_str, i_conv, field);//OTHER CASES MUST FREE old_str INSIDE RESPECTIVE FUNCTIONS or INSIDE respective scopes
	else
		return (old_str);
	return (new_str);
}

char	*ft_zero(const char *s, char *old_str, int i_conv, int field)
{
	char	*s2;
	char	*str_field;
	char	*new_str;

	if ((s[i_conv] == 'd' || s[i_conv] == 'i') && old_str[0] == '-')
		field--;
	str_field = ft_itoa(field);
	if (str_field == NULL)
		return (NULL);
	s2 = ft_strjoin(".", str_field);
	new_str = ft_strjoin(s2, "d");
	free(s2);
	s2 = ft_strjoin(new_str, s);
	free(new_str);
	if (s2 == NULL)
	{
		free(str_field);
		return (NULL);
	}
	new_str = ft_dot((const char *)s2, old_str, 1 + (int)ft_strlen(str_field));
	free(str_field);
	free(s2);
	return (new_str);
}
