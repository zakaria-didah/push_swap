/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:27:00 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 17:47:45 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../push_swap.h"
# include "get_next_line.h"

void	push_swap_checker(t_stack **a, t_stack **b, char **arr, int i);
int		validate(char **arr);
char	**read_input(void);
int		ft_putstr(char *c);
int		ft_puterror(char *c);
int		__continue(char **arr);

// UTILS
t_stack	*addnew(int element);
int		is_sorted(t_stack *head);
size_t	listlen(t_stack *head);
void	apply(char **arr);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

#endif
