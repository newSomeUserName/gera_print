/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-23 10:40:59 by tgerman           #+#    #+#             */
/*   Updated: 2026-10-23 10:40:59 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	(void )argc;
	(void )argv;
	// int x = 0;
	// ft_printf("%d<-printLen\n", ft_printf("%X\n", 17));
	// ft_printf("%d<-printLen\n", ft_printf("%p\n", &x));
	// printf("%d<-printLen\n", printf("%X\n", 17));
	// printf("%d<-printLen\n", printf("%X\n", 17));
	// printf("%d<-printLen\n", printf("%p\n", &x));
	ft_printf("%s\n", HEX_LOW);
	return (0);
}
