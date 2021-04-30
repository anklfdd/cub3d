/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:07:07 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/28 20:18:10 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line(char *line, t_map *map)
{
	char	**word;
	int		err;

	word = ft_split(line, ' ');
	err = ft_check_flag(word, map);
	ft_free_w(word);
	return (ft_error(err));
}

int	ft_check_map(t_map *map, t_list **l_map)
{
	int		err;
	t_list	*tmp;
	int		i;
	int		plr;

	err = 0;
	map->cnt_spr = 0;
	tmp = *l_map;
	i = -1;
	plr = 0;
	map->map = (char **)ft_calloc((ft_lstsize(*l_map) + 1), sizeof(char *));
	while (tmp)
	{
		map->map[++i] = ft_strdup(tmp->content);
		if (ft_sym_in_map(map->map[i], &(map->cnt_spr)) != 0)
			return (ft_error(8));
		tmp = tmp->next;
	}
	if (map->cnt_spr != 0)
		map->spr = (t_sprite *)ft_calloc(map->cnt_spr, sizeof(t_sprite));
	err = ft_init_map(map, &plr);
	if (err != 0)
		ft_free_w(map->map);
	return (ft_error(err));
}

int	get_next_line_in_cub(int fd, t_map *map, char *line)
{
	int		c_flag;
	int		err;
	char	fflag;

	c_flag = 0;
	fflag = 0;
	err = 0;
	map->l_map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (fflag == 1 && *line != '\0' && map->l_map != NULL)
		{
			free(line);
			return (ft_error(6));
		}
		if (*line == '\0')
			fflag = 1;
		else if (c_flag++ < 8)
		{
			fflag = 0;
			if (ft_check_line(line, map) != 0)
			{
				free(line);
				return (4);
			}		
		}
		else
		{
			fflag = 0;
			ft_lstadd_back(&map->l_map, ft_lstnew_size(line, ft_strlen(line) + 1));
		}
		free(line);
	}
	free(line);
	if (map->l_map == NULL || *line != '\0')
		return (ft_error(7));
	//тогда в конце карты всегда должен быть энтер (любое колличество)
	// if (*line != '\0')
	// 	ft_lstadd_back(&map->l_map, ft_lstnew(line));
	return (0);
}

int	ft_parser(char *fname, t_map *map)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (8);
	if (get_next_line_in_cub(fd, map, line) != 0)
		return (-1);
	if (ft_check_map(map, &map->l_map) != 0)
	// {
	// 	ft_lst_free(&map->l_map);
		return (-1);
	// }
	//разобраться как теперь фришить а то лики
	// if (err != 0)
	// 	ft_free_w(map->map);
	ft_lst_free(&map->l_map);
	return (0);
}
