/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:52:10 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/26 13:08:16 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

long long	cub_atoi(char str)
{
	long long	neg;
	long long	num;
	int			cnt;

	cnt = 0;
	num = 0;
	neg = 1;
	if (str == ' ')
		return (1);
	else if (!ft_isdigit(str))
		return (0);
	num = str - '0';
	if (cnt > 1)
		num = 0;
	return (num * neg);
}

int	map(t_info	info)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	data.img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.b, &data.l, &data.e);
	set_direction(&data, &info);
	data_init(&data, &info);
	textures_init(&data, &info);
	clear_screen(&data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 0, &handle_exit, 0);
	mlx_loop(data.mlx);
	return (0);
}
