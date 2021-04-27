/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:22:18 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:02:10 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int sym, size_t num)
{
	char	*string;
	size_t	a;

	string = (char *)str;
	a = 0;
	while (a != num)
	{
		string[a] = sym;
		a++;
	}
	return (string);
}
