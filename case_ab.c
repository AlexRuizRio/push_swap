/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:32 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 23:50:05 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_placeb(b, c);
	if (i < f_index(a, c))
		i = f_index(a, c);
	return (i);
}

int	case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_placeb(b, c))
		i = ft_lstsize(b) - find_placeb(b, c);
	if ((i < (ft_lstsize(a) - f_index(a, c))) && f_index(a, c))
		i = ft_lstsize(a) - f_index(a, c);
	return (i);
}

int	case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (f_index(a, c))
		i = ft_lstsize(a) - f_index(a, c);
	i = find_placeb(b, c) + i;
	return (i);
}

int	case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_placeb(b, c))
		i = ft_lstsize(b) - find_placeb(b, c);
	i = f_index(a, c) + i;
	return (i);
}
