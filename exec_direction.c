/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:53:30 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/19 17:12:51 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	set_direction(t_data *data, t_info *info)
{
	data->worldMap = info->map;
    data->posX = info->user_x; // 위치
    data->posY = info->user_y; // 위치
	if (info->direction == 'N')
		set_direction_n(data, info);
	else if (info->direction == 'S')
		set_direction_s(data, info);
	else if (info->direction == 'W')
		set_direction_w(data, info);
	else if (info->direction == 'E')
		set_direction_e(data, info);
	
}
void	set_direction_n(t_data *data, t_info *info)
{
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
}
void	set_direction_s(t_data *data, t_info *info)
{
	data->dirX = 1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = -0.66;
}
void	set_direction_w(t_data *data, t_info *info)
{
	data->dirX = 0;
	data->dirY = 1;
	data->planeX = 0.66;
	data->planeY = 0;
}
void	set_direction_e(t_data *data, t_info *info)
{
	data->dirX = 0;
	data->dirY = -1;
	data->planeX = -0.66;
	data->planeY = 0;
}


