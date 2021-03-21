/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:51:54 by gavril            #+#    #+#             */
/*   Updated: 2021/03/21 20:39:27 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(int code)
{
	if (code == 1)
		ft_putstr_fd("Неправильное количество аргументов\n", 2);
	if (code == 2)
		ft_putstr_fd("Неверный формат\n", 2);
	if (code == 3)
		ft_putstr_fd("Файл не существует\n", 2);
	if (code == 4)
		ft_putstr_fd("Нет одного из флагов\n", 2);
	if (code == 5)
		ft_putstr_fd("Плохая карта\n", 2);
	if (code == 6)
		ft_putstr_fd("Много игроков\n", 2);
	// if (code == 7)
	// exit (1);
}
