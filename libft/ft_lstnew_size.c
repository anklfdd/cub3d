#include "libft.h"

t_list	*ft_lstnew_size(void *content, size_t size)
{
	t_list	*lst;

	lst = (t_list *)ft_calloc(1, sizeof(t_list *));
	lst->content = ft_calloc(size, 1);
	ft_memcpy(lst->content, content, size);
	lst->next = 0;
	return (lst);
}
