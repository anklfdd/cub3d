/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasia <anastasia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:43:38 by anastasia         #+#    #+#             */
/*   Updated: 2021/02/24 19:21:44 by anastasia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include <stdio.h>
# include <stddef.h>

typedef struct	s_window
{
	int			width;
	int			hide;
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

#endif
