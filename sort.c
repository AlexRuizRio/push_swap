/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:09:34 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/14 14:17:31 by alruiz-d         ###   ########.fr       */
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
	printf("size del stackA: %d\n", ft_stcksize(*stacka) );
	if (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
	{
		pb(stacka, &stackb, 1);
		printf("size del stackA: %d\n", ft_stcksize(*stacka) );
	}
	
	if (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
		pb(stacka, &stackb, 1);
	printf("size del stackA: %d\n", ft_stcksize(*stacka) );
	if (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
		order_upto_3(stacka, &stackb);
	return (stackb);
}

// t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)

void	order_upto_3(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	int		i;

	i = best_option(*stacka, *stackb); // Acabar esta funcion
	/*
	while (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
	{
		tmp = stacka;
		i = best_option(*stacka, *stackb);
	}
	*/
}

// otro ARCHIVO Y PROBLAMENTE HAYA QUE HACER 2 ARCHIVOS UNO A Y OTRO B 
int	best_option(t_stack *stacka, t_stack *stackb)
{
	int		i;
	int		a;
	t_stack	*tmp;

	tmp = stacka;
	i = rrarrb_case(stacka, stackb, stacka->nbr);
	printf ("El rrarrb da: %d\n", i);
	while (tmp)
	{
		a = rarb_case (stacka, stackb, tmp->nbr);
		printf ("El rarb da: %d\n", a);
		if (i > a)
			i = rarb_case (stacka, stackb, tmp->nbr);
		a = rrarrb_case ( stacka, stackb, tmp->nbr);
		printf ("El rrarrb da: %d\n", a);
		if (i > a)
			i = rrarrb_case ( stacka, stackb, tmp->nbr);
		a = rarrb_case (stacka, stackb, tmp->nbr);
		printf ("El rarrb da: %d\n", a);
		if (i > a)
			i = rarrb_case (stacka, stackb, tmp->nbr);
		a = rrarb_case(stacka, stackb, tmp->nbr);
		printf ("El rrarb da: %d\n", a);
		if (i > a)
			i = rrarb_case(stacka, stackb, tmp->nbr);
		tmp = tmp->next;
		printf ("=\n");
	}
	return (i);
	
}

// ARCHIVO CASE 
int	rarb_case (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = find_placeb(stackb, c);
	if (i < ft_index(stacka, c))
		i = ft_index (stacka, c);
	return (i);
}
int	rrarrb_case (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = 0;

	if(find_placeb(stackb, c))
		i = ft_stcksize(stackb) - find_placeb(stackb, c);
	if ((i < (ft_stcksize(stacka) - find_placeb(stacka, c)) && ft_index(stacka, c)))
	i = ft_stcksize(stacka) - ft_index(stacka,c);
	return (i);
}

int	rrarb_case (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = 0;
	if (ft_index(stacka, c))
		i = ft_stcksize(stacka) - ft_index (stacka, c);
	i = find_placeb(stackb, c) + 1;
	return (i);
}
int	rarrb_case (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = 0;
	if (find_placeb(stackb, c))
		i = ft_stcksize(stackb) - find_placeb (stackb, c);
	i = ft_index(stacka, c) + i;
	return (i);
}
// ARCHIVO UTILS

int	ft_index (t_stack *stacka, int nbr)
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

int find_placeb (t_stack *stackb, int num)
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
	return(i);
}

int find_placea (t_stack *stacka, int num)
{
	int	i;
	t_stack *tmp;

	if (num > stacka->nbr && num < ft_stcklast(stacka)->nbr)
	i = 0;
	else if (num > max(stacka) || num < min(stacka))
		i = ft_index(stacka, min(stacka));
	else
	{
		tmp = stacka->next;
		while (stacka->nbr > num || tmp->nbr < num)
		{
			stacka = stacka->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int	min(t_stack *ab)
{
	int i;

	i = ab->nbr;
	while(ab)
	{
		if (ab->nbr < i)
			i = ab->nbr;
		ab = ab->next;
	}
	return (i);
}

int	max(t_stack *ab)
{
	int i;

	i = ab->nbr;
	while(ab)
	{
		if (ab->nbr > i)
			i = ab->nbr;
		ab = ab->next;
	}
	return (i);
}

// Apply_c

int	apply_rarb (t_stack **stacka, t_stack **stackb, long num, char ab)
{
	if (ab == 'a')
	{
		while ((*stacka)->nbr != num && find_placeb (stackb, num) > 0)
			rr(stacka, stackb, 1);
		while ((*stacka)->nbr != num)
			ra(stacka, 1);
		while (find_placeb(*stackb, num) > 0)
			rb(stackb, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		while ((*stackb)->nbr != num && find_placea (stacka, num) > 0)
			rr (stacka, stackb, 1);
		while ((*stackb)->nbr != num)
			rb(stackb, 1);
		while (find_placea(*stacka, num) > 0)
			rb(stacka, 1);
		pa(stacka, stackb, 1);
	}
	return (-1);
}

int apply_rrarrb(t_stack **stacka, t_stack **stackb, long num, char ab)
{
	if (ab == 'a')
	{
		while ((*stacka)->nbr != ab && find_placeb(*stackb, num) > 0)
			rrr(stacka, stackb, 1);
		while((*stacka)->nbr != num)
			rra(stacka, 1);
		while(find_placeb(*stackb, num))
			rrb(stackb, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		
	}
}