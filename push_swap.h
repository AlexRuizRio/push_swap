/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:17:28 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 20:27:37 by alruiz-d         ###   ########.fr       */
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
void	ft_stckadd_back(t_stack **lst, t_stack *new, t_stack *former);
void	enter_data(int count, long *argvi, t_stack **stacka);
int		sacarstring(int argc, char *argv[], long *argi);
char	**ft_split(char const *s, char c); // revisar cuando meta la libft
int		ft_isdigit(int c); // revisar cuando meta la libft
void	ft_stckclear(t_stack**lst);
t_stack	*ft_stcklast(t_stack *lst);
int		ft_stcksize(t_stack *lst);
int		checksorted(t_stack *stacka);
/*
void	sort(t_stack **stacka);
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
int		rarb_casea(t_stack *stacka, t_stack *stackb, int num);
int		rrarrb_casea(t_stack *stacka, t_stack *stackb, int num);
int		rrarb_casea(t_stack *stacka, t_stack *stackb, int num);
int		rarrb_casea(t_stack *stacka, t_stack *stackb, int num);
int		rarb_caseb(t_stack *stacka, t_stack *stackb, int num);
int		rrarrb_caseb(t_stack *stacka, t_stack *stackb, int num);
int		rrarb_caseb(t_stack *stacka, t_stack *stackb, int num);
int		rarrb_caseb(t_stack *stacka, t_stack *stackb, int num);
int		apply_rarb(t_stack **stacka, t_stack **stackb, long num, char ab);
int		apply_rrarrb(t_stack **stacka, t_stack **stackb, long num, char ab);
int		apply_rrarb(t_stack **stacka, t_stack **stackb, long num, char ab);
int		apply_rarrb(t_stack **stacka, t_stack **stackb, int num, char ab);
int		ft_index(t_stack *stacka, int nbr);
int		find_placeb(t_stack *stackb, int num);
int		find_placea(t_stack *stacka, int num);
*/

int		min(t_stack *ab);
int		max(t_stack *ab);
void	mainquicksort(long data[], int n);

t_stack		*ft_lstlast(t_stack *lst);
void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		sa(t_stack **a, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **a, int j);
void		rrb(t_stack **b, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		rrr_sub(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_find_index(t_stack *a, int nbr);
int			find_placeb(t_stack *stack_b, int num);
int			find_placea(t_stack *a, int nbr);
void		sort(t_stack **stack_a);
int			ft_checksorted(t_stack *stack_a);
void		ft_sort_big(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a);
t_stack		*ft_parse(int argc, char **argv);
t_stack		*ft_parse_args_quoted(char **argv);
void		ft_freestr(char **lst);
int			ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb(t_stack *a, t_stack *b, int c);
int			ft_rotate_type_ab(t_stack *a, t_stack *b);
int			ft_rotate_type_ba(t_stack *a, t_stack *b);
int			ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void		ft_rrb(t_stack **b, int j);
void		ft_check_sub(t_stack **a, t_stack **b, char *line);
char		*ft_check(t_stack **a, t_stack **b, char *line);
void		ft_checker_sub(t_stack **a, t_stack **b, char *line);
t_stack		*ft_process(int argc, char **argv);
void		ft_sb(t_stack **b, int j);
void		algorithm(int argc, char **argv);
void		ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sub_process(char **argv);
void		ft_error_ch(void);

#endif