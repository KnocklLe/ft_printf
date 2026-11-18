/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:32:50 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 10:42:59 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_unsigned(unsigned long long nb, int *count)
{
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10, count);
	ft_putchar(nb % 10 + '0', count);
}
