/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_only_six.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:43:09 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 11:52:40 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

int	check_only_six_util(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'N' && \
			s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

void	check_only_six(char *argv[])
{
	char	*str;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(1);
	str = get_next_line(fd);
	while (str)
	{
		if (check_only_six_util(str) == 0)
		{
			free(str);
			parsing_error(1);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
