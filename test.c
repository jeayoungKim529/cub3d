#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include "./minilibx_mms_20210621/mlx.h"


#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
    int rotate_left;
    int rotate_right;
} t_data;


void move_player(t_data *data);
int main_loop(t_data *data);


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void clear_screen(t_data *data)
{
    for (int y = 0; y < screenHeight; y++)
    {
        for (int x = 0; x < screenWidth; x++)
        {
            my_mlx_pixel_put(data, x, y, 0x000000);  // 0x000000은 검은색
        }
    }
}

int key_press(int keycode, t_data *data)
{
    if (keycode == 13) data->move_forward = 1;
    if (keycode == 1)  data->move_backward = 1;
    if (keycode == 0)  data->rotate_left = 1;
    if (keycode == 2)  data->rotate_right = 1;
    if (keycode == 53) exit(0);

    move_player(data);

    clear_screen(data);

    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == 13) data->move_forward = 0;
    if (keycode == 1)  data->move_backward = 0;
    if (keycode == 0)  data->rotate_left = 0;
    if (keycode == 2)  data->rotate_right = 0;

    main_loop(data);

    return (0);
}

void move_player(t_data *data)
{
    // double moveSpeed = 0.05;
    double moveSpeed = 0.1;
    double rotSpeed = 0.03;

    if (data->move_forward)
    {
        if (!worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)])
            data->posX += data->dirX * moveSpeed;
        if (!worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)])
            data->posY += data->dirY * moveSpeed;
    }
    if (data->move_backward)
    {
        if (!worldMap[(int)(data->posX - data->dirX * moveSpeed)][(int)(data->posY)])
            data->posX -= data->dirX * moveSpeed;
        if (!worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * moveSpeed)])
            data->posY -= data->dirY * moveSpeed;
    }
    if (data->rotate_right)
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
        data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
        data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
    }
    if (data->rotate_left)
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
        data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
        data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
    }
}

int main_loop(t_data *data)
{
    // move_player(data);
    clear_screen(data);

    for (int x = 0; x < screenWidth; x++)
    {
        double cameraX = 2 * x / (double)screenWidth - 1;
        double rayDirX = data->dirX + data->planeX * cameraX;
        double rayDirY = data->dirY + data->planeY * cameraX;

        int mapX = (int)data->posX;
        int mapY = (int)data->posY;

        double sideDistX, sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        if (side == 0) perpWallDist = (sideDistX - deltaDistX);
        else           perpWallDist = (sideDistY - deltaDistY);

        int lineHeight = (int)(screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

        int color;
        switch(worldMap[mapX][mapY])
        {
            case 1:  color = 0xFF0000;  break;
            case 2:  color = 0x00FF00;  break;
            case 3:  color = 0x0000FF;  break;
            case 4:  color = 0xFFFFFF;  break;
            default: color = 0xFFFF00;  break;
        }

        if (side == 1) color = color / 2;

        for (int y = drawStart; y < drawEnd; y++)
            my_mlx_pixel_put(data, x, y, color);
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int main()
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Raycaster");
    data.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    data.posX = 22;
    data.posY = 12;
    data.dirX = -1;
    data.dirY = 0;
    data.planeX = 0;
    data.planeY = 0.66;

    data.move_forward = 0;
    data.move_backward = 0;
    data.rotate_left = 0;
    data.rotate_right = 0;

    mlx_loop_hook(data.mlx, main_loop, &data);
    mlx_hook(data.win, 2, 1L<<0, key_press, &data);
    mlx_hook(data.win, 3, 1L<<1, key_release, &data);
    mlx_loop(data.mlx);

    return (0);
}