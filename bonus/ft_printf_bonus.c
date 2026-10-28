

#include "ft_printf_bonus.h"

static const char	*ft_parse_flags(const char *f, t_spec *spec)
{
	while (*f == '-' || *f == '0' || *f == '#' || *f == '+' || *f == ' ')
	{
		if (*f == '-')
			spec->minus = 1;
		else if (*f == '0')
			spec->zero = 1;
		else if (*f == '#')
			spec->hash = 1;
		else if (*f == '+')
			spec->plus = 1;
		else if (*f == ' ')
			spec->space = 1;
		f++;
	}
	return (f);
}

static const char	*ft_parse_num(const char *f, long *out)
{
	*out = 0;
	while (*f >= '0' && *f <= '9')
	{
		*out = *out * 10 + (*f - '0');
		f++;
	}
	return (f);
}

static const char	*ft_parse_spec(const char *f, t_spec *spec)
{
	ft_bzero(spec, sizeof(t_spec));
	spec->prec = -1;
	f = ft_parse_flags(f, spec);
	f = ft_parse_num(f, &spec->width);
	if (*f == '.')
	{
		f++;
		f = ft_parse_num(f, &spec->prec);
	}
	spec->conv = *f;
	return (f);
}

static int	ft_dispatch(t_spec spec, va_list *ap)
{
	if (spec.conv == 'c')
		return (ft_print_char(va_arg(*ap, int), spec));
	if (spec.conv == 's')
		return (ft_print_str(va_arg(*ap, char *), spec));
	if (spec.conv == 'p')
		return (ft_print_ptr(va_arg(*ap, void *), spec));
	if (spec.conv == 'd' || spec.conv == 'i')
		return (ft_print_int(va_arg(*ap, int), spec));
	if (spec.conv == 'u')
		return (ft_print_nbr(va_arg(*ap, unsigned int), spec, DEC, ""));
	if (spec.conv == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), spec, 0));
	if (spec.conv == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), spec, 1));
	if (spec.conv == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_spec	spec;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format = ft_parse_spec(format + 1, &spec);
			if (!spec.conv)
				break ;
			count += ft_dispatch(spec, &ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
