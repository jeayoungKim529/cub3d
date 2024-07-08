/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:45 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 18:40:24 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

int	init_type(t_info *info, char *str, int i)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	if (i > 2)
		parsing_error(1);
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
		info->NO = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
		info->SO = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
		info->WE = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
		info->EA = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "F", 2) == 0)
		info->F = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "C", 2) == 0)
		info->C = ft_strdup(tmp[1]);
	else
		return (0);
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
	return (1);
}

int	init_six(t_info *info)
{
	char	*str;
	int		fd;
	int		num;
	int		row;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(1);
	num = 0;
	row = 0;
	str = get_next_line(fd);
	while (str && num < 6)
	{
		if (ft_strlen(str) > 0)
		{
			num += init_type(info, str, 0);
		}
		row++;
		free(str);
		str = get_next_line(fd);
	}
	if (num != 6)
		parsing_error(1);
	close(fd);
	return (row + 1);
}
