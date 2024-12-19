/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:09:34 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/19 01:18:40 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksorted(t_stack *stacka)
{
	int	i;

	i = stacka->nbr;
	while (stacka)
	{
		if (i > stacka->nbr)
			return (0);
		i = stacka->nbr;
		stacka = stacka->next;
	}
	return (1);
}

void	sort_upto_3(t_stack **stacka, t_stack **stackb)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stacka) > 3 && !checksorted(*stacka))
	{
		tmp = *stacka;
		i = rotate_ab(*stacka, *stackb);
		while (i >= 0)
		{
			if (i == case_rarb(*stacka, *stackb, tmp->nbr))
				i = apply_rarb(stacka, stackb, tmp->nbr, 'a');
			else if (i == case_rrarrb(*stacka, *stackb, tmp->nbr))
				i = apply_rrarrb(stacka, stackb, tmp->nbr, 'a');
			else if (i == case_rarrb(*stacka, *stackb, tmp->nbr))
				i = apply_rarrb(stacka, stackb, tmp->nbr, 'a');
			else if (i == case_rrarb(*stacka, *stackb, tmp->nbr))
				i = apply_rrarb(stacka, stackb, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stacka)
{
	t_stack	*stackb;

	stackb = NULL;
	if (ft_lstsize(*stacka) > 3 && !checksorted(*stacka))
		pb(stacka, &stackb, 0);
	if (ft_lstsize(*stacka) > 3 && !checksorted(*stacka))
		pb(stacka, &stackb, 0);
	if (ft_lstsize(*stacka) > 3 && !checksorted(*stacka))
		sort_upto_3(stacka, &stackb);
	if (!checksorted(*stacka))
		sort_three(stacka);
	return (stackb);
}

t_stack	**sort_a(t_stack **stacka, t_stack **stackb)
{
	int		i;
	t_stack	*tmp;

	while (*stackb)
	{
		tmp = *stackb;
		i = rotate_ba(*stacka, *stackb);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stacka, *stackb, tmp->nbr))
				i = apply_rarb(stacka, stackb, tmp->nbr, 'b');
			else if (i == case_rarrb_a(*stacka, *stackb, tmp->nbr))
				i = apply_rarrb(stacka, stackb, tmp->nbr, 'b');
			else if (i == case_rrarrb_a(*stacka, *stackb, tmp->nbr))
				i = apply_rrarrb(stacka, stackb, tmp->nbr, 'b');
			else if (i == case_rrarb_a(*stacka, *stackb, tmp->nbr))
				i = apply_rrarb(stacka, stackb, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stacka);
}

void	sort(t_stack **stacka)
{
	t_stack	*stackb;
	int		i;

	stackb = NULL;
	if (ft_lstsize(*stacka) == 2)
		sa(stacka, 0);
	else
	{
		stackb = sort_b(stacka);
		stacka = sort_a(stacka, &stackb);
		i = f_index(*stacka, min(*stacka));
		if (i < ft_lstsize(*stacka) - i)
		{
			while ((*stacka)->nbr != min(*stacka))
				ra(stacka, 0);
		}
		else
		{
			while ((*stacka)->nbr != min(*stacka))
				rra(stacka, 0);
		}
	}
}
