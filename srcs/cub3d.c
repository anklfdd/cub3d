/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:22:27 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/27 17:18:22 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map *map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (argc == 2)
	{
		if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".cub", 4) == 0)
		{
			if (ft_parser(argv[1], map) == 0)
				init_mlx(map);
			else
				exit(1);
		}
	}
	else if (argc == 3)
	{
		if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".cub", 4) == 0)
		{
			if (ft_strncmp(argv[2], "--save", 6) == 0)
			{
				if (ft_parser(argv[1], map) == 0)
				{
					map->mlx.mlx = mlx_init();
					map->mlx.addr = (int *)ft_calloc(map->win.width * map->win.height, sizeof(int));
					texture_init(map->wall, &map->tex, &map->mlx);
					ft_rayc(map);
					save_bmp(map);
				}
				ft_putstr_fd("screen ok\n", 0);
			}
		}
	}
	else
		ft_putstr_fd("Что-то не подал, дружок\n", 0);
	free(map);
	return (0);
}
