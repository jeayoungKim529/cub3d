/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:53:30 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/22 11:20:47 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	set_direction(t_data *data, t_info *info)
{
	data->world_map = info->map;
    data->pos_x = info->user_x; // 위치
    data->pos_y = info->user_y; // 위치
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
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}
void	set_direction_s(t_data *data, t_info *info)
{
	data->dir_x = 1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = -0.66;
}
void	set_direction_w(t_data *data, t_info *info)
{
	data->dir_x = 0;
	data->dir_y = 1;
	data->plane_x = 0.66;
	data->plane_y = 0;
}
void	set_direction_e(t_data *data, t_info *info)
{
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_x = -0.66;
	data->plane_y = 0;
}


