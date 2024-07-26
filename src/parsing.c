/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:55:55 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 14:59:38 by jeakim           ###   ########.fr       */
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
	printf("direction : %c\n", (char)info->direction);
	printf("user_x : %zu\n", info->user_x);
	printf("user_y : %zu\n", info->user_y);
	printf("\n");
	printf_map(info);
}

void	check_cub_file(int argc, char *argv[], t_info *info)
{
	int		num;
	char	**s;

	if (argc != 2)
		parsing_error(2);
	s = ft_split(argv[1], '.');
	num = 0;
	while (s[num])
		num++;
	if (ft_strncmp(s[num - 1], "cub", 4) != 0)
		parsing_error(2);
	while (num >= 0)
	{
		free(s[num]);
		num--;
	}
	free(s);
	info->file = ft_strdup(argv[1]);
	if (!info->file)
		parsing_error(2);
}

void	init_info(t_info *info)
{
	int	i;

	info->map_w = 0;
	info->map_h = 0;
	info->map = NULL;
	info->file = NULL;
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	i = -1;
	while (++i < 3)
		info->f[i] = 0;
	i = -1;
	while (++i < 3)
		info->c[i] = 0;
}

void	parsing(int argc, char *argv[], t_info *info)
{
	int	row;

	init_info(info);
	check_cub_file(argc, argv, info);
	row = init_type(info, 0, 0, 0);
	init_map(info, row);
	check_map(info);
	check_texture(info);
	init_user(info);
}
