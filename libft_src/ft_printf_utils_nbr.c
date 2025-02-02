/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:56:55 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 14:14:14 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_u(unsigned int n, int fd)
{
	int	res;
	int	num;

	res = 0;
	if (n > 9)
	{
		num = ft_putnbr_fd_p(n / 10, fd);
		if (num == -1)
			return (-1);
		res += num;
		num = ft_putnbr_fd_p(n % 10, fd);
		if (num == -1)
			return (-1);
		res += num;
		return (res);
	}
	else
		if (ft_putchar_fd_p(n + '0', fd) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_fd_hex(unsigned int n, int fd, int mode)
{
	char	*hex_lower;
	char	*hex_upper;
	int		res;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	res = 1;
	if (n > 15)
	{
		res += ft_putnbr_fd_hex(n / 16, 1, mode);
		if (res == 0)
			return (-1);
	}
	if (mode == 1)
	{
		if (ft_putchar_fd_p(hex_upper[n % 16], fd) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd_p(hex_lower[n % 16], fd) == -1)
			return (-1);
	}
	return (res);
}

int	ft_putnbrstr_fd_hex(unsigned long n, int fd)
{
	char	*hex_lower;
	int		res;

	hex_lower = "0123456789abcdef";
	res = 1;
	if (n > 15)
	{
		res += ft_putnbrstr_fd_hex(n / 16, 1);
		if (res == -1)
			return (-1);
	}
	if (ft_putchar_fd_p(hex_lower[n % 16], fd) == -1)
		return (-1);
	return (res);
}

int	ft_putstr_fd_hex(void *s, int fd)
{
	int		res;

	if (ft_putstr_fd_p("0x", 1) == -1)
		return (-1);
	res = ft_putnbrstr_fd_hex((unsigned long)s, fd);
	if (res == -1)
		return (-1);
	return (res + 2);
}
