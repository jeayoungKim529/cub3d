/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_user.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:35:25 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 13:03:13 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	check_only_one_user(t_info *info)
{
	size_t	i;
	size_t	j;
	int		flag;

	flag = FALSE;
	i = -1;
	while (++i < info->map_h)
	{
		j = -1;
		while (++j < info->map_w)
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' || \
				info->map[i][j] == 'E' || info->map[i][j] == 'W')
			{
				if (flag == TRUE)
					parsing_error(5);
				else
				{
					info->direction = info->map[i][j];
					flag = TRUE;
				}
			}
		}
	}
}

void	check_user_location(t_info *info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < info->map_h)
	{
		j = -1;
		while (++j < info->map_w)
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' || \
				info->map[i][j] == 'E' || info->map[i][j] == 'W')
			{
				info->user_x = i;
				info->user_y = j;
				info->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	init_user(t_info *info)
{
	check_only_one_user(info);
	check_user_location(info);
}
