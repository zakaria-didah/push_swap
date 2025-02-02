/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:15:18 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:11:05 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_some_instructions(t_stack **a, t_stack **b, char **arr, int max)
{
	if ((*b)->prev)
	{
		if ((*a) && get_index(arr, (*a)->element) > max + 1)
			rr(a, b);
		else
			rb(b);
	}
}

int	ft_putstr(char *c)
{
	int	count;

	count = 0;
	if (!c)
		return (count += write(1, "(null)", 6));
	while (*c)
	{
		count += write(1, c, 1);
		c++;
	}
	return (count);
}

int	ft_puterror(char *c)
{
	int	count;

	count = 0;
	while (*c)
	{
		count += write(2, c, 1);
		c++;
	}
	return (count);
}

void	prepare_and_push(t_stack **head, int len, int i)
{
	if (i <= len / 2)
	{
		while (i > 0)
		{
			ra(head);
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			rra(head);
			i++;
		}
	}
	pb(head, get_head_b());
}

void	prepare_to_push(t_stack **head, int len, int i)
{
	if (i <= len / 2)
	{
		while (i > 0 && i)
		{
			ra(head);
			i--;
		}
	}
	else
	{
		while (i < len && i)
		{
			rra(head);
			i++;
		}
	}
}
