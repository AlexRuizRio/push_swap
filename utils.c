/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:42:38 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 23:46:36 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number num will get 
// after it is being pushed to the stack_b.
int	find_placeb(t_stack *stack_b, int num)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num > stack_b->nbr && num < ft_stcklast(stack_b)->nbr)
		i = 0;
	else if (num > max(stack_b) || num < min(stack_b))
		i = f_index(stack_b, max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < num || tmp->nbr > num)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_placea(t_stack *stack_a, int num)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num < stack_a->nbr && num > ft_stcklast(stack_a)->nbr)
		i = 0;
	else if (num > max(stack_a) || num < min(stack_a))
		i = f_index(stack_a, min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > num || tmp->nbr < num)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int	min(t_stack *stacka)
{
	int		i;

	i = stacka->nbr;
	while (stacka)
	{
		if (stacka->nbr < i)
			i = stacka->nbr;
		stacka = stacka->next;
	}
	return (i);
}

int	max(t_stack *stacka)
{
	int		i;

	i = stacka->nbr;
	while (stacka)
	{
		if (stacka->nbr > i)
			i = stacka->nbr;
		stacka = stacka->next;
	}
	return (i);
}
