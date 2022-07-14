/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:33:49 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/11 14:15:40 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putstr(const char *str);
void	ft_putnbr(long long int nb);
int		ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *str);
int		ft_print_s(va_list tab);
int		ft_print_d(va_list tab);
int		ft_print_small_x(va_list tab);
int		ft_printf(const char *str, ...);
int		ft_check_base(char *base);
int		ft_redirect(const char *str, va_list tab, int pos);
int		ft_unsi_putnbr_base(unsigned long long nbr, char *base);
int		ft_putlen(int nb);

#endif
