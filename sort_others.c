/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:52:48 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 23:45:59 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ba(t_stack *a, t_stack *b)
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

int	rotate_type_ab(t_stack *a, t_stack *b)
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

void	sort_three(t_stack **stack_a)
{
	if (min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a, 0);
		if (!checksorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (f_index(*stack_a, max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
