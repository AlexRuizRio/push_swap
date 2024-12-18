# include "push_swap.h"

int	apply_rarb (t_stack **stacka, t_stack **stackb, long num, char ab)
{
	if (ab == 'a')
	{
		while ((*stacka)->nbr != num && find_placeb (*stackb, num) > 0)
			rr(stacka, stackb, 1);
		while ((*stacka)->nbr != num)
			ra(stacka, 1);
		while (find_placeb(*stackb, num) > 0)
			rb(stackb, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		while ((*stackb)->nbr != num && find_placea (*stacka, num) > 0)
			rr (stacka, stackb, 1);
		while ((*stackb)->nbr != num)
			rb(stackb, 1);
		while (find_placea(*stacka, num) > 0)
			ra(stacka, 1);
		pa(stacka, stackb, 1);
	}
	return (-1);
}

int	apply_rrarrb(t_stack **stacka, t_stack **stackb, long num, char ab)
{
	if (ab == 'a')
	{
		while ((*stacka)->nbr != num && find_placeb(*stackb, num) > 0)
			rrr(stacka, stackb, 1);
		while ((*stacka)->nbr != num)
			rra(stacka, 1);
		while (find_placeb(*stackb, num) > 0)
			rrb(stackb, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		while ((*stackb)->nbr != num && find_placea(*stacka, num) > 0)
			rrr(stacka, stackb, 1);
		while ((*stackb)->nbr != num)
			rrb(stackb, 1);
		while (find_placea(*stacka, num) > 0)
			rra(stacka, 1);
		pa(stacka, stackb, 1);
	}
	return (-1);
}

int	apply_rrarb(t_stack **stacka, t_stack **stackb, long num, char ab)
{
	if (ab == 'a')
	{
		while ((*stacka)->nbr != num)
			rra(stacka, 1);
		while (find_placeb(*stackb, num) > 0)
			rb(stackb, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		while (find_placea(*stacka, num) > 0)
			rra(stacka, 1);
		while ((*stackb)->nbr != num)
			rb (stackb, 1);
		pa(stacka, stackb, 1);
	}
	return (-1);
}

int	apply_rarrb(t_stack **stacka, t_stack **stackb, int num, char ab)
{
	if (ab == 'a')
	{
		while ((*stacka)->nbr != num)
			ra(stacka, 1);
		while (find_placeb(*stackb, num) > 0)
			rrb (stackb, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		while (find_placea(*stacka, num) > 0)
			ra(stacka, 1);
		while ((*stackb)->nbr != num)
			rrb(stackb, 1);
		pa(stacka, stackb, 1);
	}
	return (-1);
}
