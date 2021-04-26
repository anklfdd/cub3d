/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturazer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasia <anastasia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:17:25 by gavril            #+#    #+#             */
/*   Updated: 2021/04/26 23:12:37 by anastasia        ###   ########.fr       */
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
		ptr = mlx_xpm_file_to_image(mlx->mlx,
		wall[i], &tex->width[i], &tex->height[i]);
		tex->texture[i] =
		(int *)mlx_get_data_addr(ptr, &bpp, &line_len, &endian);
		i++;
	}
}
