/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:42:19 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/12 14:20:14 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h" 
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
char	*ft_conv(int chr, va_list ap);
char	*ft_ptoa(unsigned long long int n);
char	*ft_uitoa(unsigned int n, char c);
char	*ft_flag(const char *s, char *old_str, int i_conv);
int		ft_isflag(const char *s, char flag, int i_conv);
char	*ft_dot(const char *s, char *old_str, int i_conv);
char	*ft_hash(const char *s, char *old_str, int i_conv);
char	*ft_field(const char *s, char *old_str, int i_conv);

#endif