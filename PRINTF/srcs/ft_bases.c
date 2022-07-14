/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:40:41 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/11 14:27:57 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (ft_strlen(base) <= 1)
		return (1);
	return (0);
}

int	ft_unsi_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long	i;
	unsigned long long	len;

	i = 0;
	len = ft_strlen(base);
	if (ft_check_base(base))
		return (0);
	if (nbr > len - 1)
		i += ft_unsi_putnbr_base(nbr / len, base);
	i += write(1, &base[nbr % len], 1);
	return (i);
}
