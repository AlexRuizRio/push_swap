/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:52:48 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/19 01:19:06 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->nbr))
			i = case_rarb_a(a, b, tmp->nbr);
		if (i > case_rrarrb_a(a, b, tmp->nbr))
			i = case_rrarrb_a(a, b, tmp->nbr);
		if (i > case_rarrb_a(a, b, tmp->nbr))
			i = case_rarrb_a(a, b, tmp->nbr);
		if (i > case_rrarb_a(a, b, tmp->nbr))
			i = case_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->nbr))
			i = case_rarb(a, b, tmp->nbr);
		if (i > case_rrarrb(a, b, tmp->nbr))
			i = case_rrarrb(a, b, tmp->nbr);
		if (i > case_rarrb(a, b, tmp->nbr))
			i = case_rarrb(a, b, tmp->nbr);
		if (i > case_rrarb(a, b, tmp->nbr))
			i = case_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

void	sort_three(t_stack **stacka)
{
	if (min(*stacka) == (*stacka)->nbr)
	{
		rra(stacka, 0);
		sa(stacka, 0);
	}
	else if (max(*stacka) == (*stacka)->nbr)
	{
		ra(stacka, 0);
		if (!checksorted(*stacka))
			sa(stacka, 0);
	}
	else
	{
		if (f_index(*stacka, max(*stacka)) == 1)
			rra(stacka, 0);
		else
			sa(stacka, 0);
	}
}
