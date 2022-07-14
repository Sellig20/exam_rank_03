#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(const char *str)
{
	int i = 0;
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
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_print_s(va_list tab)
{
	char *str;

	str = va_arg(tab, char *);
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr(str);
	return (ft_strlen(str));
}

void	ft_putnbr(long long nb)
{
	long n;

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
	int len = 0;

	if (nb == 0)
		len = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	if (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_print_d(va_list tab)
{
	int nb;

	nb = va_arg(tab, int);
	ft_putnbr(nb);
	return (ft_putlen(nb));
}

int	ft_unsi_putnbr_base(unsigned long long int nb, char *base)
{
	unsigned long long i;
	unsigned long long len;

	i = 0;
	len = ft_strlen(base);
	if (nb > len - 1)
		i += ft_unsi_putnbr_base(nb / len, base);
	i += write(1, &base[nb % len], 1);
	return (i);
}

int	ft_print_x(va_list tab)
{
	int hexa = 0;
	hexa = ft_unsi_putnbr_base((long long)va_arg(tab, unsigned int), "0123456789abcdef");
	return (hexa);
}

int ft_redirect(const char *str, va_list tab, int i)
{
	int count = 0;

	if (str[i] == 's')
		count += ft_print_s(tab);
	if (str[i] == 'd')
		count += ft_print_d(tab);
	if (str[i] == 'x')
		count += ft_print_x(tab);
	if (str[i] == '%')
		count += write(1, "%", 1);
	return (count);
}

int ft_printf(const char *str, ...)
{
	va_list tab;
	int i;
	int count;

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

int main()
{
	char *str = "Juan";
	int nb = 2900;
	printf("%d\n", ft_printf("Je m'appelle %s, j'ai %d ans et %x kk\n", str, nb, 2));
	return (0);
}
