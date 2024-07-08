/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:05 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 13:30:41 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	parsing_error(int flag)
{
	printf("Error %d\n", flag);
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
