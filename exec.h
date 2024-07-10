/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:40:49 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/10 20:58:28 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include <math.h>
# include "./minilibx_mms_20210621/mlx.h"
#include <stdlib.h>


//화면 크기와 맵 크기 정의
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TURN_LEFT 123
#define TURN_RIGHT 124
#define MOVE_FORWARD 13
#define MOVE_BACKWARD 1
#define MOVE_LEFT 0
#define MOVE_RIGHT 2


typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    int move_forward;
    int move_backward;
    int move_left;
    int move_right;
    int rotate_left;
    int rotate_right;
	char **worldMap;
	int mapHeight;
	int mapWidth;
	unsigned char	floor[3];
	unsigned char	ceiling[3];
} t_data;



#include "cub.h"
#include "parsing.h"

#endif