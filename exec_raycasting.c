// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   exec_raycasting.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/22 11:33:44 by jimchoi           #+#    #+#             */
// /*   Updated: 2024/07/23 21:16:02 by jimchoi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "exec.h"


// typedef struct s_dda{
// 	double	ray_dir_x;
// 	double	ray_dir_y;
// 		int	map_x; // ray
// 		int	map_y;
// 		double	side_dist_x; // 현재 위치에서 다음 x까지의 광선 길이
// 		double	side_dist_y; // 현재 위치에서 다음 y까지의 광선 길이
// 		double	delta_x; // n-1 에서 n까지의 x길이
// 		double	delta_y; // n-1 에서 n까지의 y길이
// 	double	prep_wall_dist; //벽부터 카메라 평면의 거리
// 			int	step_x;
// 		int	step_y;// x, y 어느 방향으로 움직일지
// 		int	hit; // 충돌 여부	
// 		int	side; // 벽면 어느축인지

// } t_dda;


// // init_ray: 광선 초기화
// // calculate_step_and_side_dist: DDA 알고리즘 변수 초기화
// // perform_dda: DDA 알고리즘 수행
// // calculate_wall_distance: 벽까지 거리 계산
// // calculate_line_height_and_draw_range: 벽 높이와 드로잉 범위 계산
// // draw_texture: 텍스처 드로잉

// void	init_ray(t_data *data, t_dda *d, int x)
// {
// 	double	camera;

// 	camera = 2 * x / (double)640 - 1;
// 	d->ray_dir_x = data->dir_x + data->plane_x * camera;
// 	d->ray_dir_y =  data->dir_y + data->plane_y  * camera;
	

// }
// void	set_delta_dist(t_dda *d)
// {
// 	if (d->ray_dir_x == 0)
// 		d->delta_x = 1e30;
// 	else
// 		d->delta_x = 1 / d->ray_dir_x;;
// 	if (d->ray_dir_y == 0)
// 	    d->delta_y = 1e30;
// 	else
// 		d->delta_y = 1 / d->ray_dir_y;

// }

// void	init_dda(t_data *data, t_dda *d)
// {
// 	if (d->ray_dir_x < 0)
// 	{
// 		d->step_x = -1;
// 		d->side_dist_x = (data->pos_x - d->map_x) * d->delta_x;
// 	}
// 	else
// 	{
// 		d->step_x = 1;
//         d->side_dist_x = (d->map_x + 1.0 - data->pos_x) * d->delta_x;
// 	}
// 	if (d->ray_dir_y < 0)
// 	{
//         d->step_y = -1;
//         d->side_dist_y = (data->pos_y - d->map_y) * d->delta_y;
//     }
// 	else
// 	{
// 		d->step_y = 1;
//         d->side_dist_y = (d->map_y + 1.0 - data->pos_y) * d->delta_y;
// 	}
// }
// void	get_wall_distance(t_dda *d)
// {
// 	int side;
// 	int wall;


// }

// void	dda(t_data *data, t_dda *d, int *side)
// {
// 	while (1)
// 	{
// 		// printf("3step[%d][%d]\n",d->step_x, d->step_y);

// 		if (d->side_dist_x < d->side_dist_y)
// 		{
// 			d->side_dist_x += d->delta_x;
//             d->map_x += d->step_x;
// 			*side = 0;
// 		}
// 		else
// 		{
// 			d->side_dist_y += d->delta_y;
//             d->map_y += d->step_y;
// 			*side = 1;
// 		}
// 		printf("3map_x[%d][%d]\n",d->map_x, d->map_y);
// 		printf("3step[%d][%d]\n",d->step_x, d->step_y);
// 		if (cub_atoi(data->world_map[d->map_x][d->map_y]) > 0)
// 			break;
// 	}
// }
// void	cal_distance(t_data *data)
// {

// }
// void	cal_line_height(t_data *data)
// {}

// // void draw_texture(t_data *data, int x, int tx, double pwd)
// // {
// // 	int	y;
// // 	int color;
// // 	int	ty;
// // 	double    t_pos;
// // 	double    step;
// // // printf("pwd = %d\n", pwd);
// // // if (pwd == 0)
// // // 	pwd= 1;
// // int line_height = (int)(480 / pwd);
// // 	int start = -((int)line_height) / 2 + 480 / 2;
// // 	int end = ((int)line_height) / 2 + 480 / 2;
// // 	if (start < 0) start = 0;
// // 	if (end >= 480) end = 480 - 1;

// // 	step = 1.0 * data->texture[0].height / line_height;
// // 	t_pos = (start - 480 / 2 + line_height / 2) * step;
// // 	y = start - 1;
// // 	while (y++ < end)
// // 	{
// // 		ty = (int)t_pos % (data->texture[0].height - 1);
// // 		t_pos += step;
// // 		color = data->texture[0].data[data->texture[0].height * ty + tx];
// // 		my_mlx_pixel_put(data, x, y, color);
// // 	}
// // }


// void draw_texture(t_data *data, int x, int texX, double perp_wall_dist, int side) {
//     int lineHeight = (int)(480 / perp_wall_dist);
//     int drawStart = -lineHeight / 2 + 480 / 2;
//     if (drawStart < 0) drawStart = 0;
//     int drawEnd = lineHeight / 2 + 480 / 2;
//     if (drawEnd >= 480) drawEnd = 480 - 1;

//     double step = 1.0 * data->texture[0].height / lineHeight;
//     double texPos = (drawStart - 480 / 2 + lineHeight / 2) * step;

//     for (int y = drawStart; y < drawEnd; y++) {
//         int texY = (int)texPos & (data->texture[0].height - 1);
//         texPos += step;
//         int color = data->texture[0].data[data->texture[0].height * texY + texX];
//         my_mlx_pixel_put(data, x, y, color);
//     }
// }

// int	main_loop(t_data * data)
// {
// 	t_dda	d;
// 	int		x;
// 	int		side;
// 	int		wall_x;
// 	double		prep_wall_dist;
// 	int tx;
// 	x = -1;
// 	while (++x < 640)
// 	{
// 		d.map_x = (int)data->pos_x;
// 		d.map_y = (int)data->pos_y;
// 		init_ray(data, &d, x);
// 		printf("1[%d][%d]\n",d.map_x, d.map_y);
// 		// printf("1step[%d][%d]\n",d.step_x, d.step_y);

// 		set_delta_dist(&d);
// 		// printf("2step[%d][%d]\n",d.step_x, d.step_y);
// 			printf("1d.delta: %f %f\n",d.delta_x, d.delta_y);
// 		init_dda(data, &d);
		
// 		dda(data, &d, &side);

// 		// prep_wall_dist = d.side_dist_x - d.delta_x;
// 		// if (side == 0)
// 		// 	prep_wall_dist = (d.side_dist_y - d.delta_y);
// 		// 	printf("2d.delta: %f %f\n",d.delta_x, d.delta_y);
// 		if (side == 0) prep_wall_dist = (d.side_dist_x- d.delta_x);
//         else           prep_wall_dist = (d.side_dist_y - d.delta_y);
		
// 		wall_x = (int)(data->pos_x + prep_wall_dist * d.ray_dir_x);
// 		if (side == 0)
// 			wall_x = (int)(data->pos_y + d.ray_dir_y * prep_wall_dist);
// 		wall_x -= (int)wall_x;
// 		tx = (int)(wall_x * (double)data->texture[0].width);
// 		if ((side == 0 && d.ray_dir_x > 0) || (side == 1 && d.ray_dir_y < 0))
// 			tx = data->texture[0].width - tx - 1;
// 		draw_texture(data, x, tx, prep_wall_dist, side);
// 	}
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:33:44 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/23 21:16:02 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

typedef struct s_dda {
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
} t_dda;

void init_ray(t_data *data, t_dda *d, int x) {
    double camera_x;

    camera_x = 2 * x / (double)640 - 1;
    d->ray_dir_x = data->dir_x + data->plane_x * camera_x;
    d->ray_dir_y = data->dir_y + data->plane_y * camera_x;
}

void set_delta_dist(t_dda *d) {
    if (d->ray_dir_x == 0)
        d->delta_dist_x = 1e30;
    else
        d->delta_dist_x = fabs(1 / d->ray_dir_x);
    if (d->ray_dir_y == 0)
        d->delta_dist_y = 1e30;
    else
        d->delta_dist_y = fabs(1 / d->ray_dir_y);
}

void init_dda(t_data *data, t_dda *d) {
    if (d->ray_dir_x < 0) {
        d->step_x = -1;
        d->side_dist_x = (data->pos_x - d->map_x) * d->delta_dist_x;
    } else {
        d->step_x = 1;
        d->side_dist_x = (d->map_x + 1.0 - data->pos_x) * d->delta_dist_x;
    }
    if (d->ray_dir_y < 0) {
        d->step_y = -1;
        d->side_dist_y = (data->pos_y - d->map_y) * d->delta_dist_y;
    } else {
        d->step_y = 1;
        d->side_dist_y = (d->map_y + 1.0 - data->pos_y) * d->delta_dist_y;
    }
}

void perform_dda(t_data *data, t_dda *d) {
    while (!d->hit) {
        if (d->side_dist_x < d->side_dist_y) {
            d->side_dist_x += d->delta_dist_x;
            d->map_x += d->step_x;
            d->side = 0;
        } else {
            d->side_dist_y += d->delta_dist_y;
            d->map_y += d->step_y;
            d->side = 1;
        }
        if (cub_atoi(data->world_map[d->map_x][d->map_y]) > 0)
            d->hit = 1;
    }
}

double calculate_perp_wall_dist(t_dda *d) {
    if (d->side == 0)
	return (d->side_dist_x - d->delta_dist_x);
        // return (d->map_x - d->ray_dir_x + (1 - d->step_x) / 2) / d->ray_dir_x;
    else
	return (d->side_dist_y - d->delta_dist_y);
        // return (d->map_y - d->ray_dir_y + (1 - d->step_y) / 2) / d->ray_dir_y;
}

void draw_texture(t_data *data, int x, int texX, double perp_wall_dist, int side) {
    int lineHeight = (int)(480 / perp_wall_dist);
    int drawStart = -lineHeight / 2 + 480 / 2;
    if (drawStart < 0) drawStart = 0;
    int drawEnd = lineHeight / 2 + 480 / 2;
    if (drawEnd >= 480) drawEnd = 480 - 1;

    double step = 1.0 * data->texture[0].height / lineHeight;
    double texPos = (drawStart - 480 / 2 + lineHeight / 2) * step;

    for (int y = drawStart; y < drawEnd; y++) {
        int texY = (int)texPos & (data->texture[0].height - 1);
        texPos += step;
        int color = data->texture[0].data[data->texture[0].height * texY + texX];
        my_mlx_pixel_put(data, x, y, color);
    }
}

int main_loop1(t_data *data) {
    t_dda d;
    int x;
    int texX;
    double perp_wall_dist;

    for (x = 0; x < 640; x++) {
        d.map_x = (int)data->pos_x;
        d.map_y = (int)data->pos_y;
        d.hit = 0;

        init_ray(data, &d, x);
        set_delta_dist(&d);
        init_dda(data, &d);
        perform_dda(data, &d);

        perp_wall_dist = calculate_perp_wall_dist(&d);

        double wallX;
        if (d.side == 0)
            wallX = data->pos_y + perp_wall_dist * d.ray_dir_y;
        else
            wallX = data->pos_x + perp_wall_dist * d.ray_dir_x;
        wallX -= floor(wallX);

        texX = (int)(wallX * (double)data->texture[0].width);
        if ((d.side == 0 && d.ray_dir_x > 0) || (d.side == 1 && d.ray_dir_y < 0))
            texX = data->texture[0].width - texX - 1;

        draw_texture(data, x, texX, perp_wall_dist, d.side);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return 0;
}
