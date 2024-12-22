/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:42:23 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/22 19:46:55 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stacka;
	int		count;
	long	*argi;

	stacka = NULL;
	if (argc < 2)
		return (-1);
	count = parseo (argc, argv);
	argi = malloc(count * sizeof(long));
	if (argi == NULL)
		return (write(2, "Error\n", 6));
	if (get_string(argc, argv, argi) == 6 || checker_arg(count, argi) == 6)
	{
		free(argi);
		return (write(2, "Error\n", 6));
	}
	enter_data(count, argi, &stacka);
	free(argi);
	if (!checksorted(stacka))
		sort(&stacka);
	ft_stckclear (&stacka);
	return (0);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}
