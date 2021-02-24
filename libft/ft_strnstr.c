/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:31:04 by gavril            #+#    #+#             */
/*   Updated: 2020/11/20 18:02:06 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	ind1;
	size_t	ind2;

	ind1 = 0;
	ind2 = 0;
	if (!*str2)
		return ((char*)str1);
	while (str1[ind1] != '\0' && ind1 < len)
	{
		while (str2[ind2] == str1[ind1 + ind2] && ind2 + ind1 < len
		&& str2[ind2] != '\0')
		{
			if (str2[ind2 + 1] == '\0')
				return ((char*)&str1[ind1]);
			ind2++;
		}
		ind2 = 0;
		ind1++;
	}
	return (NULL);
}
