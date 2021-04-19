/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:43:38 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/16 22:32:57 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define DISP_W 1920
# define DISP_H 1080
# include "libft.h"
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_tex
{
	int			*texture[5];
	int			width[5];
	int			height[5];
}				t_tex;

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
    int			*addr;
    int			bpp;
    int			llen;
    int			endian;
}				t_mlx;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

typedef struct	s_color
{
	int			f;
	int			c;
}				t_color;

typedef struct	s_plr
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;

}				t_plr;

enum wall
{
	north,
	south,
	east,
	west,
	sprite
};

typedef struct	s_sprite
{
	int			x;
	int			y;
}				t_sprite;

typedef struct	s_map
{
	char		**map;
	t_color		color;
	char		*wall[5];
	t_window	win;
	t_mlx		mlx;
	t_plr		plr;
	t_tex		tex;
	t_sprite	*spr;
	size_t		cnt_spr;
}				t_map;

int				ft_parser(char *fname, t_map *map);
void			ft_error(int code);
void			init_mlx(t_map	*map);
void			texture_init(char **wall, t_tex *tex, t_mlx *mlx);

#endif
