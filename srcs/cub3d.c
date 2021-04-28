/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:22:27 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/28 21:56:09 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (argc == 2 || argc == 3)
	{
		if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".cub", 4) == 0)
		{
			if (ft_parser(argv[1], map) == 0)
			{
				if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
					save_bmp(map);
				else if (argc == 2)
					init_mlx(map);
				else
					ft_putstr_fd("Странное количество аргументов, дружок\n", 0);
			}
			else
				exit(1);
		}
		else
			ft_putstr_fd("Странное количество аргументов, дружок\n", 0);
	}
	else
		ft_putstr_fd("Странное количество аргументов, дружок\n", 0);
	return (0);
}
