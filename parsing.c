/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:55:55 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 13:15:10 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	printf_info(t_info *info)
{
	printf("NO : %s\n", info->NO);
	printf("SO : %s\n", info->SO);
	printf("WE : %s\n", info->WE);
	printf("EA : %s\n", info->EA);
	printf("F : %s\n", info->F);
	printf("C : %s\n", info->C);
}

void	check_cub_file(int argc, char *argv[], t_info *info)
{
	int		num;
	char	**s;

	if (argc != 2)
		parsing_error(0);
	s = ft_split(argv[1], '.');
	num = 0;
	while (s[num])
		num++;
	if (ft_strncmp(s[num - 1], "cub", 4) != 0)
		parsing_error(0);
	info->file = ft_strdup(argv[1]);
	if (!info->file)
		parsing_error(0);
}

void	init_type(t_info *info, char *str)
{
	char	**tmp;
	int		i;

	tmp = ft_split(str, ' ');
	i = 0;
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
	while (--i >= 0)
	{
		free(tmp[i]);
	}
	free(tmp);
}

void	init_six(t_info *info)
{
	char	*str;
	int		fd;
	int		num;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(1);
	num = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (num < 6)
		{
			init_type(info, str);
			num++;
		}
		else
		{

		}
		str = get_next_line(fd);
	}
	if (num != 6)
		parsing_error(1);
}

void	parsing(int argc, char *argv[], t_info *info)
{
	check_cub_file(argc, argv, info);
	// check_only_six(argv);
	init_six(info);
	printf_info(info);

	// check_wall();
	// init_map();
}
