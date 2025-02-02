/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:53:39 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:08:09 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_5(t_stack **a, t_stack **b, char **arr, int len)
{
	if (*a)
	{
		if (len == 5 && cc(*a, chek_indx(*a, arr, 0)) > cc(*a, chek_indx(*a,
					arr, 1)))
			prepare_and_push(a, listlen(*a), chek_indx(*a, arr, 1));
		else
		{
			prepare_and_push(a, listlen(*a), chek_indx(*a, arr, 0));
			if (listlen(*a) > 3)
				prepare_and_push(a, listlen(*a), chek_indx(*a, arr, 1));
		}
		if (len == 4)
			return (push_swap_3((*a)->element, (*a)->prev->element,
					(*a)->prev->prev->element, b), pa(a, b));
		else
		{
			if (listlen(*a) > 3)
				prepare_and_push(a, listlen(*a), chek_indx(*a, arr, 0));
			push_swap_3((*a)->element, (*a)->prev->element,
				(*a)->prev->prev->element, b);
			if ((*b)->element < (*b)->prev->element)
				sb(b);
		}
	}
	return (pa(a, b), pa(a, b));
}

void	handel_b(t_stack **a, t_stack **b, char **arr, int len)
{
	int	i;

	i = 0;
	while (*b)
	{
		i = chek_indx(*b, arr, len);
		if (i <= len / 2)
		{
			while ((*b)->element != a2i(arr[len]))
			{
				if ((*b)->prev->element == a2i(arr[len]))
					sb(b);
				else
					rb(b);
			}
		}
		else
		{
			while ((*b)->element != a2i(arr[len]))
				rrb(b);
		}
		pa(a, b);
		len--;
	}
}

void	push_swap_(t_stack **a, t_stack **b, char **arr, int len)
{
	int (min), (max), (i);
	i = 0;
	min = 1;
	t_stack(*tmp) = *a;
	if (len <= 100)
		max = 15;
	else
		max = 25;
	while (tmp)
	{
		i = get_index(arr, tmp->element);
		if (i <= max)
		{
			prepare_to_push(a, listlen(*a), chek_indx(*a, arr, i));
			pb(a, b);
			if (i < min)
				save_some_instructions(a, b, arr, max);
			min++;
			max++;
			tmp = *get_head_a();
			continue ;
		}
		tmp = tmp->prev;
	}
	return (handel_b(a, b, arr, len));
}

void	_continue(char **arr)
{
	t_stack	**a;
	int		len;

	a = get_head_a();
	len = listlen(*a);
	if (listlen(*a) == 2)
		return ((void)ft_putstr("sa\n"));
	if (listlen(*a) == 3)
		return (push_swap_3((*a)->element, (*a)->prev->element,
				(*a)->prev->prev->element, NULL));
	if (len > 3 && len < 6)
	{
		quick_sort(arr, 0, len - 1);
		push_swap_5(a, get_head_b(), arr, len);
	}
	else
	{
		quick_sort(arr, 0, len - 1);
		push_swap_(a, get_head_b(), arr, len - 1);
	}
}

int	main(int ac, char *av[])
{
	char	**arr;
	char	*res;

	res = NULL;
	int (i) = 1;
	if (ac < 2)
		return (0);
	while (ac >= 2 && i != ac)
		res = ft_strjoin_x(res, av[i++]);
	arr = ft_split(res, ' ');
	if (!arr || !*arr)
		return (ft_puterror("Error\n"), 1);
	if (!valid(arr))
	{
		ft_puterror("Error\n");
		return (free_garb(), 1);
	}
	apply(arr);
	if (is_sorted(*get_head_a()))
		return (free_garb(), 0);
	_continue(arr);
	free_garb();
	return (0);
}
