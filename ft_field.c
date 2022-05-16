/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:30:43 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/16 16:35:59 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

static char	*ft_zero(const char *s, char *old_str, int i_conv, int field);
static char	*ft_field_real(char *old_str, int field, int minus, char conv);

char	*ft_field(const char *s, char *old_str, int i_conv)
{
	int		field;
	int		len_old;
	char	*new_str;

	new_str = (char *)s;
	while (*s == '-' || *s == '0' || *s == '#' || *s == ' ' || *s == '+')
		s++;
	field = ft_atoi(s);
	len_old = (int)ft_strlen(old_str);
	if (!field || field <= len_old)
		return (old_str);
	if (ft_isflag(new_str, '0', i_conv) && !ft_isflag(new_str, '-', i_conv)
		&& !ft_isflag(new_str, '.', i_conv))
		new_str = ft_zero(new_str, old_str, i_conv, field);
	else
		new_str = ft_field_real(old_str, field,
				ft_isflag(new_str, '-', i_conv), new_str[i_conv]);
	return (new_str);
}

static char	*ft_zero(const char *s, char *old_str, int i_conv, int field)
{
	char	*s2;
	char	*str_field;
	char	*new_str;

	if ((s[i_conv] == 'd' || s[i_conv] == 'i') && old_str[0] == '-')
		field--;
	str_field = ft_itoa(field);
	if (str_field == NULL)
	{
		free (old_str);
		return (NULL);
	}
	s2 = ft_strjoin(".", str_field);
	new_str = ft_strjoin(s2, "d");
	free(s2);
	s2 = ft_strjoin(new_str, s);
	free(new_str);
	if (s2 == NULL)
	{
		free(str_field);
		free(old_str);
		return (NULL);
	}
	new_str = ft_dot((const char *)s2, old_str, 1 + (int)ft_strlen(str_field));
	free(str_field);
	free(s2);
	return (new_str);
}

static char	*ft_field_real(char *old_str, int field, int minus, char conv)
{
	char	*new_str;
	int		len_old_str;
	int		spaces;

	new_str = (char *)malloc(sizeof(char) * field + 1);
	if (new_str == NULL)
	{
		free (old_str);
		return (NULL);
	}
	len_old_str = ft_strlen(old_str);
	if (conv == 'c' && len_old_str == 0)
		len_old_str = 1;
	spaces = 0;
	if (!minus)
	{
		spaces = field - len_old_str;
		(void)ft_memset((void *)new_str, ' ', spaces);
	}
	(void)ft_memset((void *)(new_str + spaces), '\0', 2);//TO DO BEFORE TESTING WITH TESTS: return corrected length and write the WHOLE string (without stopping when 0)
	if (old_str[0] != 0)
		(void)ft_strlcpy(new_str + spaces, old_str, len_old_str + 1);
	if (minus)
	{	
		spaces = field - len_old_str;
		(void)ft_memset((void *)(new_str + len_old_str), ' ', spaces);
		(void)ft_memset((void *)(new_str + len_old_str + spaces), '\0', 1);
	}
	free(old_str);
	return (new_str);
}

/*
static char	*ft_field_real(char *old_str, int field, int minus)
{
	char	*new_str;
	int		len_old_str;
	int		spaces;

	new_str = (char *)malloc(sizeof(char) * field + 1);
	if (new_str == NULL)
		return (NULL);
	len_old_str = ft_strlen(old_str);
	spaces = 0;
	if (!minus)
	{
		spaces = field - len_old_str;
		(void)ft_memset((void *)new_str, ' ', spaces);
	}
	(void)ft_strlcpy(new_str + spaces, old_str, len_old_str + 1);
	if (minus)
	{	
		spaces = field - len_old_str;
		(void)ft_memset((void *)(new_str + len_old_str), ' ', spaces);
		(void)ft_memset((void *)(new_str + len_old_str + spaces), '\0', 1);
	}
	free(old_str);
	return (new_str);
}
*/