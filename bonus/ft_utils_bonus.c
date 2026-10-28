

#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

int	ft_putnmb_base(unsigned long nmb, char *base, int base_len)
{
	int	count;

	count = 0;
	if (nmb / base_len > 0)
		count += ft_putnmb_base(nmb / base_len, base, base_len);
	write(1, &base[nmb % base_len], 1);
	return (count + 1);
}
