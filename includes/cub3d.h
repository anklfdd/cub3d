/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:43:38 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/28 21:47:08 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define DISP_W 2560
# define DISP_H 1440
# define BPP 4
# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40
# include "libft.h"
# include <stddef.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_tex
{
	int			*texture[5];
	int			width[5];
	int			height[5];
}				t_tex;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bpp;
	int			llen;
	int			endian;
}				t_mlx;

typedef struct s_window
{
	int			width;
	int			height;
}				t_window;

typedef struct s_color
{
	int			f;
	int			c;
}				t_color;

typedef struct s_plr
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_plr;

enum e_wall
{
	north,
	south,
	east,
	west,
	sprite
};

typedef struct s_cast_sprite
{
	double		transy;
	int			spr_scrn_x;
	int			spr_h;
	int			draw_start_y;
	int			draw_end_y;
	int			spr_w;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			texx;
	int			texy;
}				t_cast_spr;

typedef struct s_sprite
{
	int			x;
	int			y;
}				t_sprite;

typedef struct s_rayc
{
	double	camx;
	double	raydirx;
	double	raydiry;
	double	dltdistx;
	double	dltdisty;
	double	sidedistx;
	double	sidedisty;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	prpwalldist;
	int		drawstart;
	int		lineheight;
	int		drawend;
	int		x;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	double	*zbuffer;
	int		y;
}	t_rayc;

typedef struct s_map
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
	t_cast_spr	c_spr;
	t_list		*l_map;
	t_rayc		rc;
}				t_map;

int				ft_parser(char *fname, t_map *map);
int				ft_error(int code);
void			init_mlx(t_map	*map);
void			texture_init(char **wall, t_tex *tex, t_mlx *mlx);
int				paint_sprites(double *zbuffer, t_map *map);
void			save_bmp(t_map *map);
void			dist_sprites(double *zbuffer, t_map *map);
int				cast_sprite(t_map *map, double *zbuffer);
int				ft_chplr(char **map, int i, int j);
void			ft_init_plr(char sym, t_plr *plr, int i, int j);
int				ft_strchar_ind(char *str, int sym);
int				ft_check_flag(char **word, t_map *map);
int				ft_init_map(t_map *map, int *pl);
int				ft_sym_in_map(char *map, size_t *cnt_spr);
int				key_press(int keycode, t_map *map);
int				ft_raycast(t_map *map);
void			floor_ceil(t_map *map);
void			ft_comp_lineh(t_map *map);
void			ft_comp_tex(t_map *map);
int				new_ff(char **map, int i, int j);

#endif
