/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:51:02 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:01:27 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	int		ind;

	ind = 0;
	while (str[ind] != '\0')
		ind++;
	str2 = (char *)malloc(ind + 1);
	ind = 0;
	while (str[ind] != '\0')
	{
		str2[ind] = str[ind];
		ind++;
	}
	str2[ind] = '\0';
	return (str2);
}
