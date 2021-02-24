/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:58:07 by gavril            #+#    #+#             */
/*   Updated: 2020/11/04 22:36:21 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	int	ind;

	ind = ft_strlen(str);
	while (ind != 0 && str[ind] != (char)sym)
		ind--;
	return (str[ind] != (char)sym ? NULL : (char*)str + ind);
}
