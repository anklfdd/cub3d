/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:22 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:06:08 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free(t_list **lst)
{
	t_list	*clr;

	if (!*lst)
		return ;
	while (*lst)
	{
		clr = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = clr;
	}
}
