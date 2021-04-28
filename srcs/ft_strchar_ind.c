/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:06:57 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 16:27:21 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strchar_ind(char *str, int sym)
{
	int		ind;

	ind = 0;
	if (!str || !sym)
		return (0);
	while (str[ind] != '\0')
	{
		if (str[ind] == sym)
			return (ind + 1);
		ind++;
	}
	if (sym == '\0')
		return (ind + 1);
	return (0);
}
