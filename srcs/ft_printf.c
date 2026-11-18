/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 07:47:22 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 10:41:44 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putptr(void *ptr, int *count)
{
	if (!ptr)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_base((uintptr_t)ptr, "0123456789abcdef", count);
	}
}

static void	ft_check(const char *format, int *i, int *count, va_list *args)
{
	if (format[*i] == '%' && format[*i + 1])
	{
		(*i)++;
		if (format[*i] == 'd' || format[*i] == 'i')
			ft_putnbr(va_arg(*args, int), count);
		else if (format[*i] == 's')
			ft_putstr(va_arg(*args, char *), count);
		else if (format[*i] == 'c')
			ft_putchar(va_arg(*args, int), count);
		else if (format[*i] == 'x')
			ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef",
				count);
		else if (format[*i] == 'X')
			ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF",
				count);
		else if (format[*i] == '%')
			ft_putchar('%', count);
		else if (format[*i] == 'p')
			ft_putptr(va_arg(*args, void *), count);
		else if (format[*i] == 'u')
			ft_putnbr_unsigned(va_arg(*args, unsigned int), count);
	}
	else
		ft_putchar(format[*i], count);
	(*i)++;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] && count != -1)
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			count = -1;
		else
			ft_check(format, &i, &count, &args);
	}
	va_end(args);
	return (count);
}
