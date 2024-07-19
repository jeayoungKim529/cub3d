/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:06 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/19 17:43:09 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	move(t_data *data)
{
	double	move_speed;
	double	rotate_speed;

	move_speed = 0.1;
	rotate_speed = 0.05;
	if (data->move_forward)
}

void	move_forward(t_data *data)
{
	if (!cub_atoi(data->world_map[(int)data->pos_x + data->dir_x * move_speed][(int)data->pos_y]))
		data->pos_x += data->dir_x * move_speed;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)data->pos_y + data->dir_y * move_speed]))
		data->pos_y += data->dir_y * move_speed;
}

void	move_backward(t_data *data)
{
	if (!cub_atoi(data->world_map[(int)data->pos_x - data->dir_x * move_speed][(int)data->pos_y]))
		data->pos_x -= data->dir_x * move_speed;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)data->pos_y - data->dir_y * move_speed]))
		data->pos_y -= data->dir_y * move_speed;
}

void move_left(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = -data->dir_y * move_speed;
	move_y = data->dir_x * move_speed;
	if (!cub_atoi(data->world_map[(int)(data->pos_x + move_x)][(int)data->pos_y]))
		data->pos_x += move_x;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)(data->pos_y + move_y)]))
		data->pos_y += move_y;
}

void move_right(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = data->dir_y * move_speed;
	move_y = -data->dir_x * move_speed;
	if (!cub_atoi(data->world_map[(int)(data->pos_x + move_x)][(int)data->pos_y]))
		data->pos_x += move_x;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)(data->pos_y + move_y)]))
		data->pos_y += move_y;
}
