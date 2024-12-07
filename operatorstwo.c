/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorstwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:11:26 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/05 10:16:03 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int j) //REVISAR ESTA FUNCION 
{
	t_stack	*tmp;

	tmp = *a;
	*a = ft_stcklast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int j) //REVISAR ESTA FUNCION 
{
	t_stack	*tmp;

	tmp = *b;
	*b = ft_stcklast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	tmp = *a;
	*a = ft_stcklast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = ft_stcklast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 1)
		write(1, "rr\n", 3);
}
