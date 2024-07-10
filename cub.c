/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:05 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 17:27:58 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	parsing_error(char *error_msg, int flag)
{
	printf("Error:%d %s\n", flag, error_msg);
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
