/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:55:55 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 18:32:14 by jeakim           ###   ########.fr       */
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
	printf("map_w : %zu\n", info->map_w);
	printf("map_h : %zu\n", info->map_h);
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

void	parsing(int argc, char *argv[], t_info *info)
{
	int	row;

	check_cub_file(argc, argv, info);
	// check_only_six(argv);
	row = init_six(info);
	init_map(info, row);
	printf_info(info);

	// check_wall();
}
