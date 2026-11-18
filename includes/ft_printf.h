/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 07:38:01 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 10:40:28 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_unsigned_putnbr(unsigned long long nb, int *count);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *count);
char	*ft_putstr(const char *str, int *count);
void	ft_putnbr(long nb, int *count);
void	ft_putnbrbase(uintmax_t nb, const char *base, int *count);

#endif