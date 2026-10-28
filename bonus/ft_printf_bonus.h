/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 10:56:22 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-28 10:56:22 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_HIGH "0123456789ABCDEF"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"

typedef struct s_spec
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	long	width;
	long	prec;
	char	conv;
}	t_spec;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnchar(char c, int n);
int		ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_putnmb_base(unsigned long nmb, char *base, int base_len);
int		ft_print_char(int c, t_spec spec);
int		ft_print_str(char *s, t_spec spec);
int		ft_print_ptr(void *p, t_spec spec);
int		ft_print_nbr(unsigned long n, t_spec spec, char *base, char *pfx);
int		ft_print_int(int n, t_spec spec);
int		ft_print_hex(unsigned int n, t_spec spec, int upper);

#endif
