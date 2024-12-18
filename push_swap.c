/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:42:23 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 21:50:37 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char *argv[]) 
{
	t_stack	*stacka;
  	int 	i;
	int 	count;
	long 	*argi;

	stacka = NULL;
	count = parseo (argc, argv);
	argi = malloc(count * sizeof(long));
	if(argi == NULL)
		return(-1);
	if (sacarstring(argc, argv, argi) == 6)
		return (-1);
  	i = checker_arg(count, argi);
  	if(i == 6)
		return(-1);
	enter_data(count, argi, &stacka);
	free(argi);
	if (!ft_checksorted(stacka))
		sort(&stacka);
	//free(&stacka);
  return (i);
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