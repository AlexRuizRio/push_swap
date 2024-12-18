/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:09:34 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 01:39:47 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    sort(t_stack **stacka)
{
    t_stack *stackb;
    int i;

    stackb = NULL;
    if (ft_stcksize(*stacka) == 2)
        sa(stacka, 1);
    else
	{
		stackb = sort_b(stacka);
		stacka = sort_a(stacka, &stackb);
	
		i = ft_index(*stacka, min(*stacka));
		if (i < ft_stcksize(*stacka) - i)
		{
			while ((*stacka)->nbr != min(*stacka))
				ra(stacka, 1);
		}
		else
		{
				while ((*stacka)->nbr != min(*stacka))
				rra(stacka, 1);
		}
	}
}
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

void sort_3 (t_stack **stacka)
{
	if (min(*stacka) == (*stacka)->nbr)
	{
		rra(stacka, 1);
		sa(stacka, 1);
	}
	else if (max(*stacka) == (*stacka)->nbr)
	{
		ra(stacka, 1);
		if (!checksorted(*stacka))
			sa(stacka, 1);
	}
	else
	{
		if (ft_index(*stacka, max(*stacka)) == 1)
			rra(stacka, 1);
		else
			sa(stacka, 1);
	}
}

t_stack	*sort_b(t_stack **stacka)
{
	t_stack	*stackb;
	
	stackb = NULL;
	if (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
		pb(stacka, &stackb, 1);
	if (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
		pb(stacka, &stackb, 1);
	if (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
		order_upto_3(stacka, &stackb);
	if (!checksorted(*stacka))
		sort_3(stacka);
	return (stackb);
}

t_stack	**sort_a(t_stack **stacka, t_stack **stackb)
{
	int		i;
	t_stack	*tmp;
	
	
	while (*stackb)
	{
		tmp = *stackb;
		
		i = best_option_a(*stacka, *stackb);
		
		while (i >= 0)
		{
			if (i == rarb_casea(*stacka, *stackb, tmp->nbr))
				i = apply_rarb(stacka, stackb, tmp->nbr, 'b');
			else if (i == rarrb_casea(*stacka, *stackb, tmp->nbr))
				i = apply_rarrb(stacka, stackb, tmp->nbr, 'b');
			else if (i == rrarrb_casea(*stacka, *stackb, tmp->nbr))
				i = apply_rrarrb(stacka, stackb, tmp->nbr, 'b');
			else if (i == rrarb_casea(*stacka, *stackb, tmp->nbr))
				i = apply_rrarb(stacka, stackb, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stacka);
}

void	order_upto_3(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	int		i;
	
	while (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
	{
		tmp = *stacka;
		i = best_option_b(*stacka, *stackb);
		while(i >= 0)
		{
			if (i == rarb_caseb(*stacka, *stackb, tmp->nbr))
				i = apply_rarb (stacka, stackb, tmp->nbr, 'a');
			else if (i == rrarrb_caseb(*stacka, *stackb, tmp->nbr))
				i = apply_rrarrb(stacka, stackb, tmp->nbr, 'a');
			else if (i == rarrb_caseb(*stacka, *stackb, tmp->nbr))
				i = apply_rarrb(stacka, stackb, tmp->nbr, 'a');
			else if (i == rrarb_caseb(*stacka, *stackb, tmp->nbr))
				i = apply_rrarb(stacka, stackb, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

// otro ARCHIVO Y PROBLAMENTE HAYA QUE HACER 2 ARCHIVOS UNO A Y OTRO B 
int	best_option_b(t_stack *stacka, t_stack *stackb)
{
	int		i;
	t_stack	*tmp;

	tmp = stacka;
	i = rrarrb_caseb(stacka, stackb, stacka->nbr);
	while (tmp)
	{
		if (i > rarb_caseb(stacka, stackb, tmp->nbr))
			i = rarb_caseb(stacka, stackb, tmp->nbr);
		if (i > rrarrb_caseb(stacka, stackb, tmp->nbr))
			i = rrarrb_caseb(stacka, stackb, tmp->nbr);
		if (i > rarrb_caseb(stacka, stackb, tmp->nbr))
			i = rarrb_caseb(stacka, stackb, tmp->nbr);
		if (i > rrarb_caseb(stacka, stackb, tmp->nbr))
			i = rrarb_caseb(stacka, stackb, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	best_option_a(t_stack *stacka, t_stack *stackb)
{
	int		i;
	t_stack *tmp;
	
	tmp = stackb;
	i = rrarrb_casea(stacka, stackb, stackb->nbr);
	while (tmp)
	{
		if (i > rarb_casea(stacka, stackb, tmp->nbr))
			i = rarb_casea(stacka, stackb, tmp->nbr);
		if (i > rrarrb_casea(stacka, stackb, tmp->nbr))
			i = rrarrb_casea(stacka, stackb, tmp->nbr);
		if (i > rarrb_casea(stacka, stackb, tmp->nbr))
			i = rarrb_casea(stacka, stackb, tmp->nbr);
		if (i > rrarb_casea(stacka, stackb, tmp->nbr))
			i = rrarb_casea(stacka, stackb, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
