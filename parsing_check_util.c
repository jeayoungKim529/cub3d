/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:43:09 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 14:36:56 by jeakim           ###   ########.fr       */
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
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	check_only_six_util(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] !='\n')
	{
		if (s[len] != '0' && s[len] != '1' && s[len] != 'N' && \
			s[len] != 'S' && s[len] != 'E' && s[len] != 'W' && is_whitespace(s[len]) != 1)
			return (-1);
		len++;
	}
	return (len);
}

// void	check_only_six(char *argv[])
// {
// 	char	*str;
// 	int		fd;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
// 		parsing_error(1);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		if (check_only_six_util(str) == 0)
// 		{
// 			free(str);
// 			parsing_error(1);
// 		}
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// }
