/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_key_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:10 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/24 19:24:28 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	handle_exit(int num)
{
	(void)num;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == MOVE_FORWARD)
		data->move_forward = 1;
	if (keycode == MOVE_BACKWARD)
		data->move_backward = 1;
	if (keycode == MOVE_LEFT)
		data->move_left = 1;
	if (keycode == MOVE_RIGHT)
		data->move_right = 1;
	if (keycode == TURN_LEFT)
	data->rotate_left = 1;
	if (keycode == TURN_RIGHT)
		data->rotate_right = 1;
	if (keycode == 53)
		exit(0);
	move(data);
	clear_screen(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == MOVE_FORWARD)
		data->move_forward = 0;
	if (keycode == MOVE_BACKWARD)
		data->move_backward = 0;
	if (keycode == MOVE_LEFT)
		data->move_left = 0;
	if (keycode == MOVE_RIGHT)
		data->move_right = 0;
	if (keycode == TURN_LEFT)
		data->rotate_left = 0;
	if (keycode == TURN_RIGHT)
		data->rotate_right = 0;
	main_loop(data);
	return (0);
}
