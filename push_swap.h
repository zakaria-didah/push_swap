/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:03:41 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:08:23 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				element;
	struct s_stack	*prev;

}					t_stack;

// MAIN UTILS
int					valid(char **arr);
int					get_index(char **arr, int num);
int					cc(t_stack *head, int len);
int					chek_indx(t_stack *a, char **arr, int num);
char				*ft_strjoin_x(char *s1, char *s2);
int					is_sorted(t_stack *head);
int					id(char *str);
char				**ft_split(const char *s, char c);
int					ft_putstr(char *c);
long				a2i(char *str);
int					ft_sqrt(int nb);
int					ft_puterror(char *c);

// LINKED LIST UTILS
t_stack				*addnew(int element);
t_stack				**get_head_a(void);
t_stack				**get_head_b(void);
void				apply(char **arr);
size_t				listlen(t_stack *head);
t_stack				*_last(t_stack *head);
t_stack				*_before_last(t_stack *head);
void				add_back(t_stack *new, int flag);

// OPERATIONS
void				sa(t_stack **head);
void				sb(t_stack **head);
void				ss(t_stack **A, t_stack **B);
void				pa(t_stack **A, t_stack **B);
void				pb(t_stack **A, t_stack **B);
void				ra(t_stack **head);
void				rb(t_stack **head);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **head);
void				rrb(t_stack **head);
void				rrr(t_stack **a, t_stack **b);

// PUSH_SWAP
void				quick_sort(char **arr, int low, int high);
int					partition(char **arr, int low, int high);
void				prepare_to_push(t_stack **head, int len, int i);
void				_swap(char **a, char **b);
void				push_swap_3(int a, int b, int c, t_stack **bb);
void				push_swap_5(t_stack **a, t_stack **b, char **arr, int len);
void				push_swap_(t_stack **a, t_stack **b, char **arr, int len);
void				handel_b(t_stack **a, t_stack **b, char **arr, int len);
void				save_some_instructions(t_stack **a, t_stack **b, char **arr,
						int max);
void				_continue(char **arr);
void				prepare_and_push(t_stack **head, int len, int i);

#endif
