/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:15:29 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:07:37 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int sym)
{
	if ((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z'))
		return (1);
	return (0);
}
