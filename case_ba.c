
#include "push_swap.h"

int	rarb_casea(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = find_placea (stacka, num);
	if (i < ft_index(stackb, num))
		i = ft_index (stackb, num);
	return (i);
}

int	rrarrb_casea(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (find_placea(a, num))
		i = ft_stcksize(a) - find_placea(a, num);
	if ((i < (ft_stcksize(b) - ft_index(b, num))) && ft_index(b, num))
		i = ft_stcksize(b) - ft_index(b, num);
	return (i);
}

int	rarrb_casea(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (ft_index(stackb, num))
		i = ft_stcksize(stackb) - ft_index (stackb, num);
	i = find_placea(stacka, num) + i;
	return (i);
}

int	rrarb_casea(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (find_placea(stacka, num))
		i = ft_stcksize(stacka) - find_placea(stacka, num);
	i = ft_index(stackb, num) + i;
	return (i);
}
