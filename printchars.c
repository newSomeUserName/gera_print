/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 10:56:49 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-28 10:56:49 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putstr(const char *s)
{
	if (s == NULL)
		return (write(1, NULL_STR, ft_strlen(NULL_STR)));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putpointer(void *p)
{
	int	count;

	if (p == NULL)
		return (ft_putstr(NIL_STR));
	count = 2;
	ft_putstr("0x");
	return (ft_putnmb_base((unsigned long)p,
			HEX_LOW, ft_strlen(HEX_LOW)) + count);
}
