/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:05 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 15:15:13 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	parsing_error(int num)
{
	num = 0;
	printf("Error\n");
	exit(1);
}

void	check_leak(void)
{
	system("leaks cub3D");
}

int	map(t_info	info);

int	main(int argc, char *argv[])
{
	t_info	info;

	parsing(argc, argv, &info);
	map(info);
	ft_free(&info);
	exit(0);
}
