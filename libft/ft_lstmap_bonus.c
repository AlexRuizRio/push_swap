/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:26:34 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/03/19 13:27:46 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*node;

	lstnew = 0;
	while (lst)
	{
		node = ft_lstnew(lst->content);
		if (!node)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		node->content = f(node->content);
		ft_lstadd_back(&lstnew, node);
		lst = lst->next;
	}
	return (lstnew);
}
