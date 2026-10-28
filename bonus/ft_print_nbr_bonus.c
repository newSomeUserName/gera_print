/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 10:56:11 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-28 10:56:11 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_count_digits(unsigned long n, t_spec spec, int base_len)
{
	int	digits;

	if (n == 0 && spec.prec == 0)
		return (0);
	digits = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		digits++;
	}
	return (digits);
}

static int	ft_count_zeros(t_spec spec, int digits, int pfx_len)
{
	if (spec.prec > digits)
		return (spec.prec - digits);
	if (spec.zero && !spec.minus && spec.prec < 0
		&& spec.width > digits + pfx_len)
		return (spec.width - digits - pfx_len);
	return (0);
}

int	ft_print_nbr(unsigned long n, t_spec spec, char *base, char *pfx)
{
	int	pfx_len;
	int	digits;
	int	zeros;
	int	pad;

	pfx_len = ft_strlen(pfx);
	digits = ft_count_digits(n, spec, ft_strlen(base));
	zeros = ft_count_zeros(spec, digits, pfx_len);
	pad = spec.width - digits - zeros - pfx_len;
	if (pad < 0)
		pad = 0;
	if (!spec.minus)
		ft_putnchar(' ', pad);
	write(1, pfx, pfx_len);
	ft_putnchar('0', zeros);
	if (digits)
		ft_putnmb_base(n, base, ft_strlen(base));
	if (spec.minus)
		ft_putnchar(' ', pad);
	return (pad + pfx_len + zeros + digits);
}

int	ft_print_int(int n, t_spec spec)
{
	if (n < 0)
		return (ft_print_nbr(-(long)n, spec, DEC, "-"));
	if (spec.plus)
		return (ft_print_nbr(n, spec, DEC, "+"));
	if (spec.space)
		return (ft_print_nbr(n, spec, DEC, " "));
	return (ft_print_nbr(n, spec, DEC, ""));
}

int	ft_print_hex(unsigned int n, t_spec spec, int upper)
{
	char	*base;
	char	*pfx;

	base = HEX_LOW;
	pfx = "0x";
	if (upper)
	{
		base = HEX_HIGH;
		pfx = "0X";
	}
	if (!spec.hash || n == 0)
		pfx = "";
	return (ft_print_nbr(n, spec, base, pfx));
}
