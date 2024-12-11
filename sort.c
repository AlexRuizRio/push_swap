
#include "push_swap.h"


void    sort(t_stack **stacka)
{
    t_stack *stackb;
    int i;

    stackb = NULL;
    if (ft_stcksize(stacka) == 2)
        sa(stacka, 1);
    else{
		stackb = sort_b(stacka); //AQUI TOCA CONTINUAR
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

// t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)

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

// otro ARCHIVO Y PROBLAMENTE HAYA QUE HACER 2 ARCHIVOS UNO A Y OTRO B 
int	best_option(t_stack *stacka, t_stack *stackb, char c)
{
	int		i;
	t_stack	*tmp;

	if (c == 'b')
		tmp = stackb;
	else if (c == 'a')
		tmp = stacka;
	while (tmp)
	{
		if (i > rarb_case (stacka, stackb, tmp->nbr))
			i = rarb_case (stacka, stackb, tmp->nbr);
		if (i > rrarrb_case ( stacka, stackb, tmp->nbr))
			i = rrarrb_case ( stacka, stackb, tmp->nbr);
		if (i > rarrb_case (stacka, stackb, tmp->nbr))
			i = rarrb_case (stacka, stackb, tmp->nbr);
		if (i > rrarb(stacka, stackb, tmp->nbr))
			i = rrarb(stacka, stackb, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
	
}

// ARCHIVO CASE 


// ARCHIVO UTILS

int	index (t_stack *stacka, int nbr)
{
	int	i;

	i = 0;
	while ( stacka->nbr != nbr)
	{
		i++;
		stacka = stacka->next;
	}
	stacka->index = 0;
	return (i);
}