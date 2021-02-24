/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:33:47 by gavril            #+#    #+#             */
/*   Updated: 2020/11/20 18:06:07 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t num)
{
	unsigned char	*sstr1;
	unsigned char	*sstr2;
	size_t			ind;

	sstr1 = (unsigned char*)str1;
	sstr2 = (unsigned char*)str2;
	ind = 0;
	while (num)
	{
		if (sstr1[ind] != sstr2[ind])
			return (sstr1[ind] - sstr2[ind]);
		ind++;
		num--;
	}
	return (0);
}
