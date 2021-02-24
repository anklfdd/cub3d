/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:06:37 by gavril            #+#    #+#             */
/*   Updated: 2020/11/04 22:46:04 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*sstr1;
	unsigned char	*sstr2;
	size_t			ind;

	sstr1 = (unsigned char*)str1;
	sstr2 = (unsigned char*)str2;
	ind = 0;
	while (ind < num && (sstr2[ind] || sstr1[ind]))
	{
		if (sstr1[ind] != sstr2[ind])
			return (sstr1[ind] - sstr2[ind]);
		ind++;
	}
	return (0);
}
