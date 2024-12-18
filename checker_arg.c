/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:44:33 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 23:18:02 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_arg(int count, long argi[])
{
	int	i;
	int	y;

	i = 0;
	while (i < count - 1)
	{
		if (argi[i] < -2147483648 || argi[i] > 2147483647)
			return (6);
		y = i;
		while (++y < count)
		{
			if (argi[i] == argi[y])
				return (6);
		}
		i++;
	}
	return (0);
}
