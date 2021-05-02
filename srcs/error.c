/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:51:54 by gavril            #+#    #+#             */
/*   Updated: 2021/05/02 17:21:04 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int code)
{
	if (code == -2)
		ft_putstr_fd(" Неправильный формат числа\n", 2);
	else if (code == -3)
		ft_putstr_fd(" Не читаемая текстура\n", 2);
	else if (code == 1)
		ft_putstr_fd(" Неправильное количество аргументов\n", 2);
	else if (code == 2)
		ft_putstr_fd(" Неверный формат\n", 2);
	else if (code == 3)
		ft_putstr_fd(" Файл не существует\n", 2);
	else if (code == 4)
		ft_putstr_fd(" Нет одного из флагов\n", 2);
	else if (code == 5)
		ft_putstr_fd(" Плохая карта\n", 2);
	else if (code == 6)
		ft_putstr_fd(" Разрыв карты\n", 2);
	else if (code == 7)
		ft_putstr_fd(" Нет карты или после карты не стоит '\\n'\n", 2);
	else if (code == 8)
		ft_putstr_fd(" Плохой символ в карте\n", 2);
	else if (code == 9)
		ft_putstr_fd(" Утекли\n", 2);
	else if (code == 10)
		ft_putstr_fd(" Игрок плохо расположен\n", 2);
	return (code);
}
