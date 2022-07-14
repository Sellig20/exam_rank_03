/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:54:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/11 14:17:50 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list tab)
{
	char	*string;

	string = va_arg(tab, char *);
	if (!string)
		return (write(1, "(null)", 6));
	ft_putstr(string);
	return (ft_strlen(string));
}

int	ft_print_d(va_list tab)
{
	int	nb;

	nb = va_arg(tab, int);
	ft_putnbr(nb);
	return (ft_putlen(nb));
}

int	ft_print_small_x(va_list tab)
{
	unsigned int	hexa;

	hexa = 0;
	hexa = ft_unsi_putnbr_base((long long int)va_arg(tab, unsigned int),
			"0123456789abcdef");
	return (hexa);
}
