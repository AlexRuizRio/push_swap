/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:17:28 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/10/21 17:43:09 by alruiz-d         ###   ########.fr       */
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
int		isnumber(const char *str);
int		checker_arg (int argc, char *argv[]);
t_stack	*ft_stcknew(void *content, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*enter_data(int argc, char *argv[]);

#endif