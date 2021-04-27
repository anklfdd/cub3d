/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:58:07 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 21:53:32 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	int		ind;
	char	*ret;

	ind = ft_strlen(str);
	while (ind != 0 && str[ind] != (char)sym)
		ind--;
	if (str[ind] != (char)sym)
		ret = NULL;
	else
		ret = (char *)str + ind;
	return (ret);
}
