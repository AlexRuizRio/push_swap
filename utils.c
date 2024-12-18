
#include "push_swap.h"

int	ft_index(t_stack *stacka, int nbr)
{
	int	i;

	i = 0;
	while (stacka->nbr != nbr)
	{
		i++;
		stacka = stacka->next;
	}
	stacka->index = 0;
	return (i);
}

int	find_placeb(t_stack *stackb, int num)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num > stackb->nbr && num < ft_stcklast(stackb)->nbr)
		i = 0;
	else if (num > max(stackb) || num < min(stackb))
		i = ft_index(stackb, max(stackb));
	else
	{
		tmp = stackb->next;
		while (stackb->nbr < num || tmp->nbr > num)
		{
			stackb = stackb->next;
			tmp = stackb->next;
			i++;
		}
	}
	return (i);
}

int	find_placea(t_stack *stacka, int num)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num < stacka->nbr && num > ft_stcklast(stacka)->nbr)
		i = 0;
	else if (num > max(stacka) || num < min(stacka))
		i = ft_index(stacka, min(stacka));
	else
	{
		tmp = stacka->next;
		while (stacka->nbr > num || tmp->nbr < num)
		{
			stacka = stacka->next;
			tmp = stacka->next;
			i++;
		}
	}
	return (i);
}

int	min(t_stack *ab)
{
	int	i;

	i = ab->nbr;
	while (ab)
	{
		if (ab->nbr < i)
			i = ab->nbr;
		ab = ab->next;
	}
	return (i);
}

int	max(t_stack *ab)
{
	int	i;

	i = ab->nbr;
	while (ab)
	{
		if (ab->nbr > i)
			i = ab->nbr;
		ab = ab->next;
	}
	return (i);
}
