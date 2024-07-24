/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:45 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/19 15:05:51 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	init_color(t_info *info, char **tmp, int flag)
{
	int		i;

	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		parsing_error("color num erorr", 2);
	i = -1;
	while (++i < 3)
	{
		if (ft_strlen_cub(tmp[i]) <= 0)
			parsing_error("color num error", 3);
		if (i == 0 && flag == 0)
			info->f[i] = ft_atoi_cub (tmp[i] + 1, 0);
		else if (flag == 0)
			info->f[i] = ft_atoi_cub(tmp[i], 0);
		else if (i == 0 && flag == 1)
			info->c[i] = ft_atoi_cub(tmp[i] + 1, 0);
		else if (flag == 1)
			info->c[i] = ft_atoi_cub(tmp[i], 0);
	}
	i = -1;
	while (++i < 3)
		free(tmp[i]);
}

void	init_texture(t_info *info, char *str)
{
	char	**tmp;
	int		i;

	tmp = ft_split(str, ' ');
	i = 0;
	while (tmp[i])
		i++;
	if (i != 2)
		parsing_error("texture file pass erorr", 2);
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
		info->no = ft_strdup_cub(tmp[1]);
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
		info->so = ft_strdup_cub(tmp[1]);
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
		info->we = ft_strdup_cub(tmp[1]);
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
		info->ea = ft_strdup_cub(tmp[1]);
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
}

int	init_six(t_info *info, char *str, int i)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
		init_texture(info, str);
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
		init_texture(info, str);
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
		init_texture(info, str);
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
		init_texture(info, str);
	else if (ft_strncmp(tmp[0], "F", 2) == 0)
		init_color(info, ft_split(str, ','), 0);
	else if (ft_strncmp(tmp[0], "C", 2) == 0)
		init_color(info, ft_split(str, ','), 1);
	else
		return (0);
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
	return (1);
}

int	init_type(t_info *info)
{
	char	*str;
	int		fd;
	int		num;
	int		row;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(strerror(errno), 1);
	num = 0;
	row = 0;
	str = get_next_line(fd);
	while (str && num < 6)
	{
		if (ft_strlen(str) > 0)
		{
			num += init_six(info, str, 0);
		}
		row++;
		free(str);
		str = get_next_line(fd);
	}
	if (num != 6)
		parsing_error(strerror(errno), 1);
	close(fd);
	return (row + 1);
}
