/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:17:28 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/11/25 17:48:12 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_stack
{
	long            nbr;
	long            index;
	struct s_stack  *next;
	struct s_stack  *prev;
}   t_stack;

int		ft_isdigi(int c);
long	ft_strlong(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_isnumber(const char *str);
int 	checker_arg (int count, long argi[]);
t_stack	*ft_stcknew(long content, long index);
void	ft_stckadd_back(t_stack **lst, t_stack *new, t_stack *former);
t_stack *enter_data(int count, long *argvi, t_stack **stacka);
char	**ft_split(char const *s, char c); // revisar cuando meta la libft
int		ft_isdigit(int c); // revisar cuando meta la libft
void	ft_stckclear(t_stack**lst);
void	mainquicksort(long data[], int n);

#endif