/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 10:56:38 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-28 10:56:38 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_HIGH "0123456789ABCDEF"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"

int	ft_putchar(char c);
int	ft_strlen(const char *s);
int	ft_putstr(const char *s);
int	ft_putpointer(void *p);
int	ft_printf(const char *format, ...);
int	ft_putnmb_base(unsigned long nmb, char *base, int base_len);
int	ft_putnmb(int nmb);
#endif
