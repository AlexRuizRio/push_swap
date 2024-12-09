
#include "push_swap.h"


void    sort(t_stack **stacka)
{
    t_stack *stackb;
    int i;

    stackb = NULL;
    if (ft_stcksize(stacka) == 2)
        sa(stacka, 1);
    else{
		stackb = sort_b(stacka); //AQUI
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

t_stack	*sort_b(t_stack **stacka)
{
	t_stack	*stackb;

	stackb = NULL;
	if (ft_stcksize(stacka) > 3 && !checksorted(stacka))
			pb(stacka, stackb, 1);
		if (ft_stcksize(stacka) > 3 && !checksorted(stacka))
			pb(stacka, stackb, 1);
		if (ft_stcksize(stacka) > 3 && !checksorted(stacka))
			order_upto_3(stacka, &stackb);

}

void	order_upto_3(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	int		i;

	while (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
	{
		tmp = stacka;
		i = best_option(*stacka, *stackb, 'b');
	}
	
}

int	best_option(t_stack *stacka, t_stack *stackb, char c)
{
	int		i;
	t_stack	*tmp;

	if (c == 'b')
		tmp = stackb;
	else if (c == 'a')
		tmp = stacka;
}