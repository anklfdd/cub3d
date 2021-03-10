/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:22:27 by anastasia         #+#    #+#             */
/*   Updated: 2021/03/10 18:59:48 by gavril           ###   ########.fr       */
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
				printf("pars error\n");
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
	// free(map);
	return (0);
}
