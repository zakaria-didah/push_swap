/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:03:17 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:12:44 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_indx(t_stack *a, char **arr, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	num = a2i(arr[num]);
	while (tmp)
	{
		if (tmp->element == num)
		{
			return (i);
		}
		i++;
		tmp = tmp->prev;
	}
	return (-1);
}

int	cc(t_stack *head, int len)
{
	int	cost;

	cost = 0;
	if (len == 1)
		return (len + 1);
	if ((size_t)len > listlen(head) / 2)
	{
		cost = listlen(head) - 1 - len + 2;
	}
	else
	{
		cost = len + 1;
	}
	return (cost);
}

int	get_index(char **arr, int num)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (a2i(arr[i]) == num)
			return (i);
		i++;
	}
	return (-1);
}

void	reset(int *a, int *b, int *c)
{
	t_stack	*stack_a;

	stack_a = *get_head_a();
	*a = stack_a->element;
	*b = stack_a->prev->element;
	*c = stack_a->prev->prev->element;
}

void	push_swap_3(int a, int b, int c, t_stack **bb)
{
	t_stack(**stack_a) = get_head_a();
	while (!is_sorted(*stack_a))
	{
		if (a > b && a > c)
		{
			if ((bb && (*bb)->prev) && ((*bb)->element < (*bb)->prev->element))
				rr(stack_a, bb);
			else
				ra(stack_a);
		}
		if (a > b && a < c)
		{
			if ((bb && (*bb)->prev) && ((*bb)->element < (*bb)->prev->element))
				ss(stack_a, bb);
			else
				sa(stack_a);
		}
		reset(&a, &b, &c);
		if ((a < b && a < c && b > c) || (a < b && a > c && b > c))
			rra(stack_a);
	}
}
