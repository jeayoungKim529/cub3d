/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:09:09 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 19:24:26 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

int	ft_isdigit_cub(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	parsing_error("color num erorr", 2);
	return (0);
}

long long	ft_atoi_cub(const char *str, int cnt)
{
	long long	neg;
	long long	num;

	num = 0;
	neg = 1;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		cnt++;
		str++;
	}
	while (*str && ft_isdigit_cub(*str) == 1)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (cnt > 1)
		num = 0;
	if (num * neg < 0 || num * neg > 255)
		parsing_error("color num error", 2);
	return (num * neg);
}

size_t	ft_strlen_cub(const char *s)
{
	size_t	len;

	len = 0;
	if (!s || s[len] == '\0')
		return (0);
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}
