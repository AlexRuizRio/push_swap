/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:17:28 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 23:57:52 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigi(int c);
long	ft_strlong(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_isnumber(const char *str);
int		parseo(int argc, char *argv[]);
int		checker_arg(int count, long argi[]);
t_stack	*ft_stcknew(long content, long index);
void	ft_stckadd_back(t_stack **lst, t_stack *new);
void	enter_data(int count, long *argvi, t_stack **stacka);
int		get_string(int argc, char *argv[], long *argi);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
void	ft_stckclear(t_stack**lst);
t_stack	*ft_stcklast(t_stack *lst);
int		ft_stcksize(t_stack *lst);
int		checksorted(t_stack *stacka);
int		min(t_stack *ab);
int		max(t_stack *ab);
t_stack	*ft_lstlast(t_stack *lst);
void	ra(t_stack **a, int j);
void	rb(t_stack **b, int j);
void	sa(t_stack **a, int j);
void	sb(t_stack **b, int j);
void	pa(t_stack **a, t_stack **b, int j);
void	pb(t_stack **stack_a, t_stack **stack_b, int j);
void	rra(t_stack **a, int j);
void	rrb(t_stack **b, int j);
void	ss(t_stack **a, t_stack **b, int j);
void	rr(t_stack **a, t_stack **b, int j);
void	rrr_sub(t_stack **b, int j);
void	rrr(t_stack **a, t_stack **b, int j);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		f_index(t_stack *a, int nbr);
int		find_placeb(t_stack *stack_b, int num);
int		find_placea(t_stack *a, int nbr);
void	sort(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
int		case_rarb_a(t_stack *a, t_stack *b, int c);
int		case_rrarrb_a(t_stack *a, t_stack *b, int c);
int		case_rarrb_a(t_stack *a, t_stack *b, int c);
int		case_rrarb_a(t_stack *a, t_stack *b, int c);
int		case_rarb(t_stack *a, t_stack *b, int c);
int		case_rrarrb(t_stack *a, t_stack *b, int c);
int		case_rrarb(t_stack *a, t_stack *b, int c);
int		case_rarrb(t_stack *a, t_stack *b, int c);
int		rotate_type_ab(t_stack *a, t_stack *b);
int		rotate_type_ba(t_stack *a, t_stack *b);
int		apply_rarb(t_stack **a, t_stack **b, int c, char ab);
int		apply_rrarrb(t_stack **a, t_stack **b, int c, char ab);
int		apply_rrarb(t_stack **a, t_stack **b, int c, char ab);
int		apply_rarrb(t_stack **a, t_stack **b, int c, char ab);
void	sort_b_till_3(t_stack **stack_a, t_stack **stack_b);

#endif