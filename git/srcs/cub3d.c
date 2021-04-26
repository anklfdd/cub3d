/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:22:27 by anastasia         #+#    #+#             */
/*   Updated: 2021/03/15 21:27:44 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc == 2)
	{
		if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".cub", 4) == 0)
		{
			if (ft_parser(argv[1], map) == 0)
				printf("OK\n");
			else
			{
				// sleep(999);
				printf("NOT OK\n");
				exit(1);
			}
		}
	}
	else if (argc == 3)
	{
		if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".cub", 4) == 0)
		{
			if (ft_strncmp(argv[2], "--save", 6) == 0)
				printf("screen ok\n");
		}
	}
	else
		ft_putstr_fd("Что-то не подал, дружок", 0);
	
	// int		offset;
	t_mlx	*mlx;
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	// int	x;
	// int	y;

	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx, map->win.width, map->win.height, "cub");
	mlx->img = mlx_new_image(mlx, map->win.width, map->win.height);
	// mlx_loop(mlx);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length,
                                 &mlx->endian);

	// offset = (y * line_length + x * (bits_per_pixel / 8));
	// int i = 0;
	// while (i < 1920 * 1080)
	// {
	// 	mlx->addr[i] = 0xFF0000;
	// 	i++;
	// }
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_loop(mlx);
	
	// free(map);
	// sleep(9999);
	return (0);
}
