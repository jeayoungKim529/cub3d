/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:41:50 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 17:35:22 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

int	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	init_dxdy(int dx[4], int dy[4])
{
	dx[0] = 0;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = -1;
	dy[0] = 1;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 0;
}

int	check_four_wall(t_info *info, int x, int y)
{
	int		dx[4];
	int		dy[4];
	int		i;
	size_t	cur_x;
	size_t	cur_y;

	init_dxdy(dx, dy);
	i = 0;
	while (i < 4)
	{
		cur_x = x + dx[i];
		cur_y = y + dy[i];
		if (cur_x < 0 || cur_x >= info->map_h || cur_y < 0 || \
				cur_y >= info->map_w)
			continue ;
		if (info->map[cur_x][cur_y] != '0' && info->map[cur_x][cur_y] != '1' &&\
				is_direction(info->map[cur_x][cur_y]) != 1)
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map_h)
	{
		j = 0;
		while (j < info->map_w)
		{
			if (info->map[i][j] == '0')
			{
				if (check_four_wall(info, i, j) != 0)
					parsing_error("wall error", 1);
			}
			j++;
		}
		i++;
	}
}
