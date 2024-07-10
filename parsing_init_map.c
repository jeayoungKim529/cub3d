/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:31:50 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 14:36:15 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	init_map_size(t_info *info, int fd, char *str)
{
	int	max_width;
	int	len;
	int	row;

	max_width = -1;
	row = 0;
	while (str)
	{
		if (ft_strlen(str) > 0)
		{
			len = check_only_six_util(str);
			if (len < 0)
				parsing_error(strerror(errno), 2);
			max_width = ft_max(max_width, len);
			row++;
		}
		free(str);
		str = get_next_line(fd);
	}
	info->map_w = max_width;
	info->map_h = row;
}

void	init_map_malloc(t_info *info)
{
	size_t	i;

	info->map = ft_calloc(sizeof(char *), info->map_h);
	i = 0;
	while (i < info->map_h)
	{
		info->map[i] = ft_calloc(sizeof(char), info->map_w);
		i++;
	}
}

void	init_map_oz(t_info *info, int fd, char *str)
{
	size_t	i;
	size_t	j;

	init_map_malloc(info);
	i = 0;
	while (i < info->map_h)
	{
		j = 0;
		while (str[j] && j < info->map_w)
		{
			info->map[i][j] = str[j];
			if (str)
			j++;
		}
		while (j < info->map_w)
		{
			info->map[i][j] = ' ';
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
}

void	init_map(t_info *info, int row)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(strerror(errno), 2);
	i = 0;
	str = get_next_line(fd);
	while (str && i < row)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	init_map_size(info, fd, str);
	close(fd);
	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(strerror(errno), 2);
	i = 0;
	str = get_next_line(fd);
	while (str && i < row)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	init_map_oz(info, fd, str);
	close(fd);
}
