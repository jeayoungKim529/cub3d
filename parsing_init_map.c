/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:31:50 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 13:17:11 by jeakim           ###   ########.fr       */
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
		if (ft_strlen_cub(str) > 0)
		{
			len = check_only_six_util(str);
			if (len < 0)
				parsing_error(2);
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

	while (ft_strlen_cub(str) == 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	i = 0;
	while (i < info->map_h)
	{
		j = 0;
		while (str[j] && str[j] != '\n' && j < info->map_w)
		{
			info->map[i][j] = str[j];
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

char	*return_str(int row, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	while (str && i < row)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (str);
}

void	init_map(t_info *info, int row)
{
	int		fd;
	char	*str;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(3);
	str = return_str(row, fd);
	init_map_size(info, fd, str);
	close(fd);
	init_map_malloc(info);
	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(3);
	str = return_str(row, fd);
	init_map_oz(info, fd, str);
	close(fd);
}
