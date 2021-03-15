/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:43:38 by anastasia         #+#    #+#             */
/*   Updated: 2021/03/15 21:27:29 by gavril           ###   ########.fr       */
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

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
    char		*addr;
    int			bits_per_pixel;
    int			line_length;
    int			endian;
}				t_mlx;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

typedef struct	s_wall
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*spr;
}				t_wall;

typedef struct	s_color
{
	int			f;
	int			c;
}				t_color;

typedef struct	s_map
{
	char		**map;
	t_color		color;
	t_wall		wall;
	t_window	win;
}				t_map;

int				ft_parser(char *fname, t_map *map);
void			ft_error(int code);

#endif
