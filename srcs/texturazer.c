/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturazer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:17:25 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 19:50:10 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_init(char **wall, t_tex *tex, t_mlx *mlx)
{
	void	*ptr;
	int		bpp;
	int		line_len;
	int		endian;
	int		i;

	i = 0;
	while (i < 5)
	{
		ptr = mlx_xpm_file_to_image(mlx->mlx, wall[i],
				&tex->width[i], &tex->height[i]);
		if (ptr == NULL)
		{
			ft_error(-3);
			exit(1);
		}
		tex->texture[i] = (int *)
			mlx_get_data_addr(ptr, &bpp, &line_len, &endian);
		i++;
	}
}
