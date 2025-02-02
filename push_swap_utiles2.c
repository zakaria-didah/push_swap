/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:37:04 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 09:37:06 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*_before_last(t_stack *head)
{
	while (head->prev->prev)
	{
		head = head->prev;
	}
	return (head);
}

t_stack	**get_head_a(void)
{
	static t_stack	*head_a = NULL;

	return (&head_a);
}

t_stack	**get_head_b(void)
{
	static t_stack	*head_b = NULL;

	return (&head_b);
}

t_stack	*_last(t_stack *head)
{
	while (head->prev)
	{
		head = head->prev;
	}
	return (head);
}

void	add_back(t_stack *new, int flag)
{
	t_stack	**head;

	if (flag)
	{
		head = get_head_a();
	}
	else
	{
		head = get_head_b();
	}
	if (!*head)
		(*head) = new;
	else
	{
		_last(*head)->prev = new;
	}
}
