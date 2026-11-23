/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 07:38:01 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/23 12:14:45 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *format, ...)__attribute__((format(printf, 1,
					2)));
void	ft_putchar(char c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_putnbr(long nb, int *count);
void	ft_putnbr_unsigned(unsigned long long nb, int *count);
void	ft_putnbr_base(uintmax_t nb, const char *base, int *count);

#endif
