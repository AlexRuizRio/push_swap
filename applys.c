/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:19 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 20:24:42 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && find_placeb(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->nbr != c)
			ra(a, 0);
		while (find_placeb(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && find_placea(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		while (find_placea(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && find_placeb(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->nbr != c)
			rra(a, 0);
		while (find_placeb(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && find_placea(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);
		while (find_placea(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			rra(a, 0);
		while (find_placeb(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_placea(*a, c) > 0)
			rra(a, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a, 0);
		while (find_placeb(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_placea(*a, c) > 0)
			ra(a, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
