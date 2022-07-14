/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:32:23 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/11 14:17:11 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_putnbr(long long int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

int	ft_putlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len = 1;
	}
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
