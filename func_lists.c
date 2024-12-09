/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:06:42 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/11/27 20:35:50 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

t_stack	*ft_stcknew(long content, long index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->nbr = content;
    node->index = index;
	node->next = NULL;
	return (node);
}

void	ft_stckadd_back(t_stack **lst, t_stack *new, t_stack *former)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
        temp->prev = former;
	}
}

void	ft_stckclear(t_stack **lst)
{
	t_stack	*tem;

	while (*lst)
	{
		tem = *lst;
		*lst = (*lst)->next;
		free(tem); 
	}
}

t_stack	*ft_stcklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
