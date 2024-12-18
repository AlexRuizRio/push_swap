/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:09:34 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/19 00:52:51 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->nbr))
				i = apply_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->nbr))
				i = apply_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->nbr))
				i = apply_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->nbr))
				i = apply_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
		sort_b_till_3(stack_a, &stack_b);
	if (!checksorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, tmp->nbr))
				i = apply_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = apply_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = apply_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, tmp->nbr))
				i = apply_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = f_index(*stack_a, min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != min(*stack_a))
				rra(stack_a, 0);
		}
	}
}
