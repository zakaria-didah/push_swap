/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:36:35 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:01:28 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!*head || !(*head)->prev)
		return ;
	tmp = *head;
	tmp1 = (*head)->prev;
	*head = (*head)->prev;
	tmp->prev = tmp1->prev;
	(*head)->prev = tmp;
}

void	sb(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!*head || !(*head)->prev)
		return ;
	tmp = *head;
	tmp1 = (*head)->prev;
	*head = (*head)->prev;
	tmp->prev = tmp1->prev;
	(*head)->prev = tmp;
}

void	ss(t_stack **A, t_stack **B)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if ((!*A || !*B) && (!(*A)->prev || !(*B)->prev))
		return ;
	tmp = *A;
	tmp1 = (*A)->prev;
	*A = (*A)->prev;
	tmp->prev = tmp1->prev;
	(*A)->prev = tmp;
	tmp = *B;
	tmp1 = (*B)->prev;
	*B = (*B)->prev;
	tmp->prev = tmp1->prev;
	(*B)->prev = tmp;
}

void	pa(t_stack **A, t_stack **B)
{
	t_stack	*b_tmp;
	t_stack	*a_tmp;

	if (!*B)
		return ;
	if (!*A)
	{
		b_tmp = *B;
		*B = (*B)->prev;
		*A = b_tmp;
		(*A)->prev = NULL;
	}
	else
	{
		b_tmp = *B;
		*B = (*B)->prev;
		a_tmp = *A;
		*A = b_tmp;
		(*A)->prev = a_tmp;
	}
}

void	pb(t_stack **A, t_stack **B)
{
	t_stack	*b_tmp;
	t_stack	*a_tmp;

	if (!*A)
		return ;
	if (!*B)
	{
		a_tmp = *A;
		*A = (*A)->prev;
		*B = a_tmp;
		(*B)->prev = NULL;
	}
	else
	{
		a_tmp = *A;
		*A = (*A)->prev;
		b_tmp = *B;
		*B = a_tmp;
		(*B)->prev = b_tmp;
	}
}
