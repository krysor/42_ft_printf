/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:42:19 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/04/28 14:33:03 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <libft.h> 
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_flag(const char *s, ...);

#endif