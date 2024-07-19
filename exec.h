/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:40:49 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/19 17:48:41 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include <math.h>
# include "./minilibx_mms_20210621/mlx.h"
#include <stdlib.h>


//화면 크기와 맵 크기 정의
// #define SCREEN_WIDTH 640
// #define SCREEN_HEIGHT 480
#define TURN_LEFT 123
#define TURN_RIGHT 124
#define MOVE_FORWARD 13
#define MOVE_BACKWARD 1
#define MOVE_LEFT 0
#define MOVE_RIGHT 2
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;


	int			size_l;
	int			bpp;
	int			endian;
}				t_img;


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
    t_img texture[4];
} t_data;



#include "cub.h"
#include "parsing.h"


//exec_direction
void	set_direction(t_data *data, t_info *info);
void	set_direction_n(t_data *data, t_info *info);
void	set_direction_s(t_data *data, t_info *info);
void	set_direction_w(t_data *data, t_info *info);
void	set_direction_e(t_data *data, t_info *info);
//exec_init
void	data_init(t_data *data, t_info *info);
void textures_init(t_data *data, t_info *info);
//exec_key_handling
int	handle_exit(int num);
int key_press(int keycode, t_data *data);
int key_release(int keycode, t_data *data);
//exec_image
int	create_rgb(int r, int g, int b);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void clear_screen(t_data *data);




#endif