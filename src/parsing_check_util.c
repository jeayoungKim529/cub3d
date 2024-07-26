/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:43:09 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 14:15:04 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'\
			|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	check_only_six_util(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
	{
		if (s[len] != '0' && s[len] != '1' && s[len] != 'N'\
				&& s[len] != 'S' && s[len] != 'E' && s[len] != 'W'\
				&& is_whitespace(s[len]) != 1)
			return (-1);
		len++;
	}
	return (len);
}
