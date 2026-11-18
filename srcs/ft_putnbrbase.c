/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:21:54 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 14:22:07 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_lengthbase(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

void	ft_putnbrbase(uintmax_t nb, const char *base, int *count)
{
	uintmax_t	lengthbase;

	lengthbase = ft_lengthbase((char *)base);
	if (nb >= lengthbase)
		ft_putnbrbase(nb / lengthbase, (char *)base, count);
	ft_putchar(base[nb % lengthbase], count);
}
