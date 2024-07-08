/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:16:31 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 18:41:32 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <sys/types.h>
// # include <sys/stat.h>

//parsing_init_type.c
void	check_cub_file(int argc, char *argv[], t_info *info);
int		init_type(t_info *info, char *str, int i);
int		init_six(t_info *info);
//parsing_init_map.c
void	init_map(t_info *info, int row);
//check_only_six.c
int		ft_max(int a, int b);
int		check_only_six_util(char *s);
void	check_only_six(char *argv[]);

#endif
