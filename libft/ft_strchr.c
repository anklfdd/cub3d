/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:51 by gavril            #+#    #+#             */
/*   Updated: 2020/11/04 22:17:29 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	while (*str)
		if (*str++ == sym)
			return ((char*)str - 1);
	if (sym == '\0')
		return ((char*)str);
	return (NULL);
}
