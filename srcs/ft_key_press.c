/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:49:34 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 17:18:07 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_code_13_0(t_map *map, int keycode)
{
	if (keycode == 13)
	{
		if (map->map[(int)(map->plr.x + map->plr.dirx
				* 0.3)][(int)map->plr.y] != '1')
			map->plr.x += map->plr.dirx * 0.1;
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y
		+ map->plr.diry * 0.3)] != '1')
			map->plr.y += map->plr.diry * 0.1;
	}
	if (keycode == 0)
	{
		if (map->map[(int)(map->plr.x - map->plr.planex
				* 0.3)][(int)map->plr.y] != '1')
			map->plr.x -= map->plr.planex * 0.1;
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y
		- map->plr.planey * 0.3)] != '1')
			map->plr.y -= map->plr.planey * 0.1;
	}
}

void	ft_code_1_2(t_map *map, int keycode)
{
	if (keycode == 1)
	{
		if (map->map[(int)(map->plr.x - map->plr.dirx
				* 0.3)][(int)map->plr.y] != '1')
			map->plr.x -= map->plr.dirx * 0.1;
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y
		- map->plr.diry * 0.3)] != '1')
			map->plr.y -= map->plr.diry * 0.1;
	}
	if (keycode == 2)
	{
		if (map->map[(int)(map->plr.x + map->plr.planex
				* 0.3)][(int)map->plr.y] != '1')
			map->plr.x += map->plr.planex * 0.1;
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y
		+ map->plr.planey * 0.3)] != '1')
			map->plr.y += map->plr.planey * 0.1;
	}
}

void	ft_code_123_124(t_map *map, int keycode, double olddirx, double oldplnx)
{
	if (keycode == 123)
	{
		olddirx = map->plr.dirx;
		map->plr.dirx = map->plr.dirx * cos(0.1) - map->plr.diry * sin(0.1);
		map->plr.diry = olddirx * sin(0.1) + map->plr.diry * cos(0.1);
		oldplnx = map->plr.planex;
		map->plr.planex = map->plr.planex
			* cos(0.1) - map->plr.planey * sin(0.1);
		map->plr.planey = oldplnx * sin(0.1)
			+ map->plr.planey * cos(0.1);
	}
	if (keycode == 124)
	{
		olddirx = map->plr.dirx;
		map->plr.dirx = map->plr.dirx * cos(-0.1)
			- map->plr.diry * sin(-0.1);
		map->plr.diry = olddirx * sin(-0.1)
			+ map->plr.diry * cos(-0.1);
		oldplnx = map->plr.planex;
		map->plr.planex = map->plr.planex * cos(-0.1)
			- map->plr.planey * sin(-0.1);
		map->plr.planey = oldplnx * sin(-0.1)
			+ map->plr.planey * cos(-0.1);
	}
}

int	key_press(int keycode, t_map *map)
{
	double	olddirx;
	double	oldplanex;

	olddirx = 0;
	oldplanex = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		ft_code_13_0(map, keycode);
	if (keycode == 0)
		ft_code_13_0(map, keycode);
	if (keycode == 1)
		ft_code_1_2(map, keycode);
	if (keycode == 2)
		ft_code_1_2(map, keycode);
	if (keycode == 123)
		ft_code_123_124(map, keycode, olddirx, oldplanex);
	if (keycode == 124)
		ft_code_123_124(map, keycode, olddirx, oldplanex);
	ft_raycast(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->mlx.img, 0, 0);
	return (0);
}
