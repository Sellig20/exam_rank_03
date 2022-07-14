/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:39:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/11 14:29:32 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_redirect(const char *str, va_list tab, int i)
{
	int	count;

	count = 0;
	if (str[i] == 's')
		count += ft_print_s(tab);
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_d(tab);
	else if (str[i] == 'x')
		count += ft_print_small_x(tab);
	else if (str[i] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	tab;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(tab, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_redirect((char *)str, tab, ++i);
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(tab);
	return (count);
}
