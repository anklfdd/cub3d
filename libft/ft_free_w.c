/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:26:19 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 15:03:27 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_w(char **word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		free(word[i]);
		word[i] = NULL;
		i++;
	}
	free(word);
	word = NULL;
}
