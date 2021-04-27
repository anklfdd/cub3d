/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:50:08 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:08:43 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					ind;
	int					sign;
	unsigned long int	res;

	ind = 0;
	sign = 1;
	res = 0;
	while ((str[ind] >= 9 && str[ind] <= 13) || str[ind] == ' ')
		ind++;
	if (str[ind] == '-' || str[ind] == '+')
	{
		if (str[ind] == '-')
			sign = -1;
		ind++;
	}
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		res = res * 10 + str[ind] - '0';
		ind++;
		if (sign > 0 && res > 9223372036854775807)
			return (-1);
		if (sign < 0 && res > 9223372036854775807)
			return (0);
	}
	return (res * sign);
}
