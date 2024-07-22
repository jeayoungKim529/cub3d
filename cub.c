/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:05 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/22 11:30:59 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	parsing_error()
{
	printf("Error\n");
	exit(1);
}

void	check_leak()
{
	system("leaks cub3D");
}

int	map(t_info	info);

int	main(int argc, char *argv[])
{
	check_leak();
	t_info	info;

	parsing(argc, argv, &info);
	map(info);

	exit(0);
}
