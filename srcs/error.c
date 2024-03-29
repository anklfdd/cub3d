/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:51:54 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 18:46:40 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int code)
{
	if (code == 0)
		return (0);
	else if (code == 1)
		ft_putstr_fd("Неправильное количество аргументов\n", 2);
	else if (code == 2)
		ft_putstr_fd("Неверный формат\n", 2);
	else if (code == 3)
		ft_putstr_fd("Файл не существует\n", 2);
	else if (code == 4)
		ft_putstr_fd("Нет одного из флагов\n", 2);
	else if (code == 5)
		ft_putstr_fd("Плохая карта\n", 2);
	return (code);
}
