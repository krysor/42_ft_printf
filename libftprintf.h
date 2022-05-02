/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:42:19 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/02 14:56:31 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h" 
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
char	*ft_conv(int chr, va_list ap);
char	*ft_uitoa(unsigned int n);
char	*ft_itoax(unsigned long long int n, char c);
void	ft_strtoupper(char *str);

#endif