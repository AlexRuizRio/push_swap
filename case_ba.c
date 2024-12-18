/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:46 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/19 00:23:34 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_placea(a, c);
	if (i < f_index(b, c))
		i = f_index(b, c);
	return (i);
}

int	case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_placea(a, c))
		i = ft_lstsize(a) - find_placea(a, c);
	if ((i < (ft_lstsize(b) - f_index(b, c))) && f_index(b, c))
		i = ft_lstsize(b) - f_index(b, c);
	return (i);
}

int	case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (f_index(b, c))
		i = ft_lstsize(b) - f_index(b, c);
	i = find_placea(a, c) + i;
	return (i);
}

int	case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_placea(a, c))
		i = ft_lstsize(a) - find_placea(a, c);
	i = f_index(b, c) + i;
	return (i);
}
