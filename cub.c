/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:05 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 11:43:49 by jeakim           ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	check_leak();
	t_info	info;

	parsing(argc, argv, &info);


	exit(0);
}
