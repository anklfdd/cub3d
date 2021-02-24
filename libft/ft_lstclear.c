/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:35:11 by gavril            #+#    #+#             */
/*   Updated: 2020/11/14 21:33:17 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *clr;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		clr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = clr;
	}
}
