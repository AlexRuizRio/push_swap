/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorsthree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:11:26 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/05 10:12:46 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	*a = (*a)->next;
	while ((*a)->next != NULL)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	tmp = *b;
	*b = (*b)->next;
	while ((*b)->next != NULL)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr_b(t_stack **b, int j)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	if (j == 1)
		write(1, "rrr\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	ft_rrr_b(b, j);
}
