/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:04:19 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 16:51:43 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(int param)
{
	(void)param;
	exit(0);
}

void	floor_ceil(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->win.width * map->win.height / 2)
	{
		map->mlx.addr[i] = map->color.c;
		i++;
	}
	while (i < map->win.width * map->win.height)
	{
		map->mlx.addr[i] = map->color.f;
		i++;
	}
}

void	init_mlx(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx,
			map->win.width, map->win.height, "cub");
	map->mlx.img = mlx_new_image(map->mlx.mlx,
			map->win.width, map->win.height);
	map->mlx.addr = (int *)mlx_get_data_addr(map->mlx.img,
			&map->mlx.bpp, &map->mlx.llen, &map->mlx.endian);
	texture_init(map->wall, &map->tex, &map->mlx);
	ft_raycast(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->mlx.img, 0, 0);
	mlx_hook(map->mlx.mlx_win, 17, 0, ft_close, 0);
	mlx_hook(map->mlx.mlx_win, 2, 0, key_press, map);
	mlx_loop(map->mlx.mlx);
}
