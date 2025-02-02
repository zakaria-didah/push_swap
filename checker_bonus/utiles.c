/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:36:32 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:00:32 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->prev)
		return ;
	tmp = _last(*head);
	_before_last(*head)->prev = NULL;
	tmp->prev = *head;
	*head = tmp;
}

void	rrb(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->prev)
		return ;
	tmp = _last(*head);
	_before_last(*head)->prev = NULL;
	tmp->prev = *head;
	*head = tmp;
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a || !*b || !(*a)->prev || !(*b)->prev)
		return ;
	tmp = _last(*a);
	_before_last(*a)->prev = NULL;
	tmp->prev = *a;
	*a = tmp;
	tmp = _last(*b);
	_before_last(*b)->prev = NULL;
	tmp->prev = *b;
	*b = tmp;
}

void	ra(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->prev)
		return ;
	tmp = *head;
	*head = (*head)->prev;
	tmp->prev = NULL;
	if (_last(*head))
		_last(*head)->prev = tmp;
}

void	rb(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->prev)
		return ;
	tmp = *head;
	*head = (*head)->prev;
	tmp->prev = NULL;
	if (_last(*head))
		_last(*head)->prev = tmp;
}
