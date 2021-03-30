/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:04:19 by gavril            #+#    #+#             */
/*   Updated: 2021/03/30 21:11:16 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(int param)
{
    (void)param;
    exit(0);
}

void	paint_line(int x, int start, int end, t_map *map)
{
	while (start < end)
	{
		mlx_pixel_put(map->mlx.mlx, map->mlx.mlx_win, x, start, 0x00FF00FF);
		start += 1;
	}
}

int		ft_rayc(t_map *map)
{
	double planex;
	double planey;
	double camx;
	double raydirx;
	double raydiry;
	double dltdistx;
	double dltdisty;
	double sidedistx;
	double sidedisty;
	int mapx;
	int mapy;
	int stepx;
    int stepy;
	int hit;
	int side;
	double prpwalldist;
	int drawstart;
	int lineheight;
	int drawend;
	int x;
	
	//plane крутить вместе с dir
	planex = 0;
	planey = 0.66;
	x = 0;	
	while (x < map->win.width)
	{
		camx = 2 * x / (double)map->win.width - 1;
		raydirx = map->plr.dirx + planex * camx;
		raydiry = map->plr.diry + planey * camx;
		mapx = (int)map->plr.x;
		mapy = (int)map->plr.y;
		// printf("%f %f\n", raydirx, raydiry);
		
		if (raydiry == 0)
			dltdistx = 0;
		else if (raydirx == 0)
			dltdistx = 1;
		else
			dltdistx = fabs (1 / raydirx);
		if (raydirx == 0)
				dltdisty = 0;
		else if (raydiry == 0)
			dltdisty = 1;
		else
			dltdisty = fabs (1 / raydiry);

		
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (map->plr.x - mapx) * dltdistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - map->plr.x) * dltdistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (map->plr.y - mapy) * dltdisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - map->plr.y) * dltdisty;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += dltdistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += dltdisty;
				mapy += stepy;
				side = 1;
			}
			if (map->map[mapx][mapy] != '4')
				hit = 1;
			if (side == 0)
				prpwalldist = (mapx - map->plr.x + (1 - stepx) / 2) / raydirx;
			else
				prpwalldist = (mapy - map->plr.y + (1 - stepy) / 2) / raydiry;
			lineheight = (int)(map->win.height / prpwalldist);
			drawstart = -lineheight / 2 + map->win.height / 2;
			if (drawstart < 0)
				drawstart = 0;
			drawend = lineheight / 2 + map->win.height / 2;
			if (drawend >= map->win.height)
				drawend = map->win.height - 1;
			
		}
		x++;
		paint_line(x, drawstart, drawend, map);
	}
	return (0);
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 53) // close
		exit(0);
		//w
	if (keycode == 13)
	{
		map->plr.y += 0.3;
	}
	// if (keycode == 0) // A
	//s
	if (keycode == 1)
	{
		map->plr.y = 0.3;
	}
	// if (keycode == 2) // D
	// if (keycode == 123) // <
	// if (keycode == 124) // >
	// ft_rayc(map);
	return (0);
}

void	init_mlx(t_map	*map)
{
	// int		offset;

	map->mlx.mlx = mlx_init();
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx, map->win.width, map->win.height, "cub");
	map->mlx.img = mlx_new_image(map->mlx.mlx, map->win.width, map->win.height);
	// mlx_loop(mlx);
	map->mlx.addr = mlx_get_data_addr(map->mlx.img, &map->mlx.bpp, &map->mlx.llen,
                                 &map->mlx.endian);

	// offset = (y * llen + x * (bpp / 8));
	// int y = 100;
	// int x = 100;
	// while (y++ < 200)
	// {
	// 	x = 100;
	// 	while (x++ < 200)
	// 		mlx_pixel_put(map->mlx.mlx, map->mlx.mlx_win, x, y, 0x00FF00FF);
	// 	// mlx->addr[i] = 0xFF0000;
	// 	// i++;
	// }
	ft_rayc(map);
	// mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_hook(map->mlx.mlx_win, 17, 0, ft_close, 0);
	mlx_hook(map->mlx.mlx_win, 2, 0, key_press, map);

	mlx_loop(map->mlx.mlx);
}
