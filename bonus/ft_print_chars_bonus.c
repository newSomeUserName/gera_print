

#include "ft_printf_bonus.h"

int	ft_print_char(int c, t_spec spec)
{
	int	pad;

	pad = spec.width - 1;
	if (pad < 0)
		pad = 0;
	if (!spec.minus)
		ft_putnchar(' ', pad);
	ft_putchar(c);
	if (spec.minus)
		ft_putnchar(' ', pad);
	return (pad + 1);
}

int	ft_print_str(char *s, t_spec spec)
{
	int	len;
	int	pad;

	if (!s && spec.prec >= 0 && spec.prec < ft_strlen(NULL_STR))
		s = "";
	else if (!s)
		s = NULL_STR;
	len = ft_strlen(s);
	if (spec.prec >= 0 && spec.prec < len)
		len = spec.prec;
	pad = spec.width - len;
	if (pad < 0)
		pad = 0;
	if (!spec.minus)
		ft_putnchar(' ', pad);
	write(1, s, len);
	if (spec.minus)
		ft_putnchar(' ', pad);
	return (pad + len);
}

int	ft_print_ptr(void *p, t_spec spec)
{
	if (!p)
	{
		spec.prec = -1;
		return (ft_print_str(NIL_STR, spec));
	}
	return (ft_print_nbr((unsigned long)p, spec, HEX_LOW, "0x"));
}
