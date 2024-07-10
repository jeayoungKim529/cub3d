/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:55:55 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 11:16:33 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	printf_map(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map_h)
	{
		j = 0;
		while (j < info->map_w)
		{
			printf("%c", info->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	printf_info(t_info *info)
{
	int	i;

	printf("NO : %s\n", info->no);
	printf("SO : %s\n", info->so);
	printf("WE : %s\n", info->we);
	printf("EA : %s\n", info->ea);
	i = -1;
	printf("F : ");
	while (++i < 3)
		printf("%d ", info->f[i]);
	printf("\n");
	i = -1;
	printf("C : ");
	while (++i < 3)
		printf("%d ", info->c[i]);
	printf("\n");
	printf("\n");
	printf("map_w : %zu\n", info->map_w);
	printf("map_h : %zu\n", info->map_h);
	printf("\n");
	printf_map(info);
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

void	init_info(t_info *info)
{
	info->map_w = 0;
	info->map_h = 0;
	info->map = NULL;
	info->file = NULL;
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
}

void	parsing(int argc, char *argv[], t_info *info)
{
	int	row;

	init_info(info);
	check_cub_file(argc, argv, info);
	row = init_type(info);
	init_map(info, row);
	printf_info(info);
	// check_wall();
}
