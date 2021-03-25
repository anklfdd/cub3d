/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:04:19 by gavril            #+#    #+#             */
/*   Updated: 2021/03/25 20:05:50 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(int param)
{
    (void)param;
    exit(0);
}

int		key_press(int keycode, int param)
{
	(void)param;
	if (keycode == 53) // close
		exit(0);
	// if (keycode == 13) // W
	// if (keycode == 0) // A
	// if (keycode == 1) // S
	// if (keycode == 2) // D
	// if (keycode == 123) // <
	// if (keycode == 124) // >

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
	int y = 100;
	int x = 100;
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(map->mlx.mlx, map->mlx.mlx_win, x, y, 0x00FF00FF);
		// mlx->addr[i] = 0xFF0000;
		// i++;
	}
	// mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_hook(map->mlx.mlx_win, 17, 0, ft_close, 0);
	mlx_hook(map->mlx.mlx_win, 2, 0, key_press, 0);

	mlx_loop(map->mlx.mlx);
}