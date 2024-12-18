
#include "push_swap.h"

int	rarb_caseb(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = find_placeb(stackb, num);
	if (i < ft_index(stacka, num))
		i = ft_index (stacka, num);
	return (i);
}

int	rrarrb_caseb(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (find_placeb(b, num))
		i = ft_stcksize(b) - find_placeb(b, num);
	if ((i < (ft_stcksize(a) - ft_index(a, num)) && ft_index(a, num)))
		i = ft_stcksize(a) - ft_index(a, num);
	return (i);
}

int	rrarb_caseb(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (ft_index(stacka, num))
		i = ft_stcksize(stacka) - ft_index (stacka, num);
	i = find_placeb(stackb, num) + i;
	return (i);
}

int	rarrb_caseb(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (find_placeb(stackb, num))
		i = ft_stcksize(stackb) - find_placeb (stackb, num);
	i = ft_index(stacka, num) + i;
	return (i);
}
