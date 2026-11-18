/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:32:50 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 07:33:54 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_usigned_putnbr(unsigned long long nb, int *count)
{
	(*count)++;
	if (nb > 9)
		ft_putnbr(nb / 10, count);
	ft_putchar(nb % 10 + '0', count);
}