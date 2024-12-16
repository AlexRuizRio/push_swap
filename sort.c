/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:09:34 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/16 14:58:03 by alruiz-d         ###   ########.fr       */
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
		if (ft_index(*stacka, max(*stacka) == 1) == 1)
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
	return (stackb);
}

t_stack	**ft_sort_a(t_stack **stacka, t_stack **stackb)
{
	int		i;
	t_stack	*tmp;
	
	sort_3(stacka);
	while (*stackb)
	{
		tmp = *stackb;
		i = 
		
	}
}

void	order_upto_3(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	int		i;

	i = best_option(*stacka, *stackb); // Acabar esta funcion
	
	while (ft_stcksize(*stacka) > 3 && !checksorted(*stacka))
	{
		tmp = stacka;
		i = best_option_a(*stacka, *stackb);
		while(i >= 0)
		{
			if (i == rarb_caseb(*stacka, *stackb, tmp->nbr))
				i = apply_rarb (stacka, stackb, tmp->nbr, 'a');
			else if (i == rrarrb_caseb(*stacka, *stackb, tmp->nbr))
				i = apply_rrarrb(stacka, stackb, tmp->nbr, 'a');
			else if (i == rarrb_caseb(stacka, stackb, tmp->nbr))
				i = apply_rarrb(stacka, stackb, tmp->nbr, 'a');
			else if (i == rrarb_caseb(stacka, stacka, tmp->nbr))
				i = apply_rrarb(stacka, stackb, tmp->nbr, 'a');
			else 
				tmp = tmp->next;
		}
	}
}

// otro ARCHIVO Y PROBLAMENTE HAYA QUE HACER 2 ARCHIVOS UNO A Y OTRO B 
int	best_option_a(t_stack *stacka, t_stack *stackb)
{
	int		i;
	int		a;
	t_stack	*tmp;

	tmp = stacka;
	i = rrarrb_caseb(stacka, stackb, stacka->nbr);
	printf ("El rrarrb da: %d\n", i);
	while (tmp)
	{
		a = rarb_caseb (stacka, stackb, tmp->nbr);
		printf ("El rarb da: %d\n", a);
		if (i > a)
			i = rarb_caseb (stacka, stackb, tmp->nbr);
		a = rrarrb_case ( stacka, stackb, tmp->nbr);
		printf ("El rrarrb da: %d\n", a);
		if (i > a)
			i = rrarrb_caseb ( stacka, stackb, tmp->nbr);
		a = rarrb_caseb (stacka, stackb, tmp->nbr);
		printf ("El rarrb da: %d\n", a);
		if (i > a)
			i = rarrb_caseb (stacka, stackb, tmp->nbr);
		a = rrarb_caseb(stacka, stackb, tmp->nbr);
		printf ("El rrarb da: %d\n", a);
		if (i > a)
			i = rrarb_caseb(stacka, stackb, tmp->nbr);
		tmp = tmp->next;
		printf ("=\n");
	}
	return (i);
}

int	best_option_a(t_stack *stacka, t_stack *stackb)
{
	int		i;
	t_stack *tmp;
	
	tmp = stackb;
	i = rrarrb_case(stacka, stackb, tmp->nbr);
	while (tmp)
	{
		if (i > rarb_case(stacka, stackb, tmp->nbr))
			i = rarb_case
	}
}

// ARCHIVO CASE B
int	rarb_caseb (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = find_placeb(stackb, c);
	if (i < ft_index(stacka, c))
		i = ft_index (stacka, c);
	return (i);
}
int	rrarrb_caseb (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = 0;

	if(find_placeb(stackb, c))
		i = ft_stcksize(stackb) - find_placeb(stackb, c);
	if ((i < (ft_stcksize(stacka) - find_placeb(stacka, c)) && ft_index(stacka, c)))
	i = ft_stcksize(stacka) - ft_index(stacka,c);
	return (i);
}

int	rrarb_caseb (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = 0;
	if (ft_index(stacka, c))
		i = ft_stcksize(stacka) - ft_index (stacka, c);
	i = find_placeb(stackb, c) + 1;
	return (i);
}
int	rarrb_caseb (t_stack *stacka, t_stack *stackb, int c)
{
	int i;

	i = 0;
	if (find_placeb(stackb, c))
		i = ft_stcksize(stackb) - find_placeb (stackb, c);
	i = ft_index(stacka, c) + i;
	return (i);
}

// ARCHIVO CASE DEL B al A

int rarb_casea (t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = find_placea (stacka, num);
	if (i < ft_index(stackb, num))
		i = ft_index (stackb, num);
	return (i);
}

int	rrarrb_casea (t_stack *stacka, t_stack *stackb, int num)
{
	int i;

	i = 0;
	if (find_placea(stacka, num))
		i = ft_stcksize(stacka) - find_placea(stacka, num);
	if ((i < (ft_stcksize(stackb) - ft_index(stackb, num))) && ft_index(stackb, num))
		i = ft_stcksize(stackb) - ft_index(stackb, num);
	return (i);
}

int	rarrb_casea (t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (ft_index(stackb, num))
		i = ft_stcksize(stackb) - find_placea (stackb, num);
	i = ft_index(stackb, num) + i;
	return (i);
}

int rrarb (t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (find_placea(stacka, num))
		i = ft_stcksize(stacka) - find_placea(stacka, num);
	i = ft_index(stackb, num) + i;
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
		while ((*stackb)->nbr != num && find_placea(*stacka, num))
			rrr(stacka, stackb, num);
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
			rb(stacka, 1);
		pb(stacka, stackb, 1);
	}
	else
	{
		while (find_placea(*stacka, num) > 1)
			rra(stacka, 1);
		while ((*stackb)->nbr != num)
			rb (stackb, 1);
		pa(stacka, stackb, 1);
	}
	return (-1);
}

int apply_rarrb (t_stack **stacka, t_stack **stackb, int num, char ab)
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