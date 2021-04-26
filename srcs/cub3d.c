/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasia <anastasia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:22:27 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/26 23:06:20 by anastasia        ###   ########.fr       */
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
			{
				ft_putstr_fd("OK\n", 0);
				init_mlx(map);
			}
			else
			{
				ft_putstr_fd("NOT OK\n", 0);
				exit(1);
			}
		}
	}
	else if (argc == 3)
	{
		if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".cub", 4) == 0)
		{
			if (ft_strncmp(argv[2], "--save", 6) == 0)
				ft_putstr_fd("screen ok\n", 0);
		}
	}
	else
		ft_putstr_fd("Что-то не подал, дружок\n", 0);
	free(map);
	return (0);
}
