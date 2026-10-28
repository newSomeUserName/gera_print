/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 10:56:32 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-28 10:56:32 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch_char(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(*ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnmb(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putnmb_base(va_arg(*ap, unsigned int), DEC, ft_strlen(DEC)));
	else if (c == 'x')
		return (ft_putnmb_base(va_arg(*ap, unsigned int),
				HEX_LOW, ft_strlen(HEX_LOW)));
	else if (c == 'X')
		return (ft_putnmb_base(va_arg(*ap, unsigned int),
				HEX_HIGH, ft_strlen(HEX_HIGH)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			count += ft_dispatch_char(format[1], &ap);
			format++;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
