/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:36:39 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:01:31 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_stack *head)
{
	if (!head)
		return (0);
	while (head->prev)
	{
		if (head->element > head->prev->element)
			return (0);
		head = head->prev;
	}
	return (1);
}

t_stack	*addnew(int element)
{
	t_stack	*new;

	new = ft_calloc(sizeof(t_stack), 1);
	new->element = element;
	new->prev = NULL;
	return (new);
}

size_t	listlen(t_stack *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		head = head->prev;
		i++;
	}
	return (i);
}

void	apply(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		add_back(addnew(a2i(arr[i++])), 1);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a || !*b || !(*a)->prev || !(*b)->prev)
		return ;
	tmp = *a;
	*a = (*a)->prev;
	tmp->prev = NULL;
	_last(*a)->prev = tmp;
	tmp = *b;
	*b = (*b)->prev;
	tmp->prev = NULL;
	_last(*b)->prev = tmp;
}
