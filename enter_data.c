/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:47:52 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 22:14:43 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enter_data(int count, long *argvi, t_stack **stacka)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = ft_stcknew(argvi[i], i);
	if (node == NULL)
		return ;
	*stacka = node;
	while (++i < count)
	{
		node = ft_stcknew(argvi[i], i);
		if (node == NULL)
		{
			ft_stckclear(stacka);
			return ;
		}
		ft_stckadd_back(stacka, node);
	}
}
