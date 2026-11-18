/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 07:47:22 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 07:45:36 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr(va_arg(args, int), &count);
			else if (format[i] == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (format[i] == 'c')
				ft_putchar(va_arg(args, int), &count);
			else if (format[i] == 'x')
				ft_putnbrbase(va_arg(args, int), "0123456789abcdef", &count);
			else if (format[i] == 'X')
				ft_putnbrbase(va_arg(args, int), "0123456789ABCDEF", &count);
			else if (format[i] == '%')
				ft_putchar('%', &count);
			else if (format[i] == 'p')
			{
				ft_putstr("0x", &count);
				ft_putnbrbase(va_arg(args, uintptr_t), "0123456789abcdef",
					&count);
			}
			else if (format[i] == "%u")
				ft_usigned_putnbr(va_arg(args, unsigned long long),
					"0123456789");
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
