/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdigs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 10:56:55 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-28 10:56:55 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnmb_base(unsigned long nmb, char *base, int base_len)
{
	int	count;

	count = 0;
	if (nmb / base_len > 0)
	{
		count += ft_putnmb_base(nmb / base_len, base, base_len);
	}
	write(1, &base[nmb % base_len], 1);
	return (count + 1);
}

int	ft_putnmb(int nmb)
{
	long	lnmb;
	int		count;

	count = 0;
	lnmb = nmb;
	if (lnmb < 0)
	{
		count++;
		ft_putchar('-');
		lnmb = -lnmb;
	}
	count += ft_putnmb_base(lnmb, DEC, ft_strlen(DEC));
	return (count);
}
