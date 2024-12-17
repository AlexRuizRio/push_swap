/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:17:28 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/17 19:29:57 by alruiz-d         ###   ########.fr       */
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
void 	enter_data(int count, long *argvi, t_stack **stacka);
char	**ft_split(char const *s, char c); // revisar cuando meta la libft
int		ft_isdigit(int c); // revisar cuando meta la libft
void	ft_stckclear(t_stack**lst);
t_stack	*ft_stcklast(t_stack *lst);
int		ft_stcksize(t_stack *lst);
int		checksorted(t_stack *stacka);
void    sort(t_stack **stacka);
t_stack	*sort_b(t_stack **stacka);
t_stack	**sort_a(t_stack **stacka, t_stack **stackb);
void	order_upto_3(t_stack **stacka, t_stack **stackb);
int		best_option_a(t_stack *stacka, t_stack *stackb);
int		best_option_b(t_stack *stacka, t_stack *stackb);
void	sa(t_stack **a, int j);
void	sb(t_stack **b, int j);
void	ss(t_stack **a, t_stack **b, int j);
void	pa(t_stack **a, t_stack **b, int j);
void	pb(t_stack **a, t_stack **b, int j);
void	ra(t_stack **a, int j);
void	rb(t_stack **b, int j);
void	rr(t_stack **a, t_stack **b, int j);
void	rra(t_stack **a, int j);
void	rrb(t_stack **b, int j);
void	rrr(t_stack **a, t_stack **b, int j);
void	rrr_b(t_stack **b, int j);
int		rarb_casea (t_stack *stacka, t_stack *stackb, int num);
int		rrarrb_casea (t_stack *stacka, t_stack *stackb, int num);
int		rrarb_casea (t_stack *stacka, t_stack *stackb, int num);
int		rarrb_casea (t_stack *stacka, t_stack *stackb, int num);
int		rarb_caseb (t_stack *stacka, t_stack *stackb, int num);
int		rrarrb_caseb (t_stack *stacka, t_stack *stackb, int num);
int		rrarb_caseb (t_stack *stacka, t_stack *stackb, int num);
int		rarrb_caseb (t_stack *stacka, t_stack *stackb, int num);
int		apply_rarb (t_stack **stacka, t_stack **stackb, long num, char ab);
int 	apply_rrarrb(t_stack **stacka, t_stack **stackb, long num, char ab);
int		apply_rrarb(t_stack **stacka, t_stack **stackb, long num, char ab);
int 	apply_rarrb(t_stack **stacka, t_stack **stackb, int num, char ab);
int		ft_index (t_stack *stacka, int nbr);
int 	find_placeb (t_stack *stackb, int num);
int 	find_placea (t_stack *stacka, int num);
int		min(t_stack *ab);
int		max(t_stack *ab);
void	mainquicksort(long data[], int n);

#endif