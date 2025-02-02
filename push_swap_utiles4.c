/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:37:11 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 12:09:49 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **head)
{
	t_stack	*tmp;

	tmp = _last(*head);
	_before_last(*head)->prev = NULL;
	tmp->prev = *head;
	*head = tmp;
	ft_putstr("rra\n");
}

void	rrb(t_stack **head)
{
	t_stack	*tmp;

	tmp = _last(*head);
	_before_last(*head)->prev = NULL;
	tmp->prev = *head;
	*head = tmp;
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = _last(*a);
	_before_last(*a)->prev = NULL;
	tmp->prev = *a;
	*a = tmp;
	tmp = _last(*b);
	_before_last(*b)->prev = NULL;
	tmp->prev = *b;
	*b = tmp;
	ft_putstr("rrr\n");
}

void	ra(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->prev;
	tmp->prev = NULL;
	if (_last(*head))
		_last(*head)->prev = tmp;
	ft_putstr("ra\n");
}

void	rb(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->prev;
	tmp->prev = NULL;
	if (_last(*head))
		_last(*head)->prev = tmp;
	ft_putstr("rb\n");
}
