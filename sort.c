
#include "push_swap.h"

void    sort(t_stack **s_stacka)
{
    t_stack *s_stackb;
    int i;

    s_stackb = NULL;
    if (ft_stcksize(s_stacka) == 2)
        sa(s_stacka);
    //continuar aqui
        
    
}
int	ft_checksorted(t_stack *stack_a)
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