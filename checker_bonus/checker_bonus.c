/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:36:15 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:12:55 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_swap_checker(t_stack **a, t_stack **b, char **arr, int i)
{
	while (arr[++i])
	{
		if (ft_strncmp(arr[i], "sa\n", 3) == 0)
			sa(a);
		else if (ft_strncmp(arr[i], "sb\n", 3) == 0)
			sb(b);
		else if (ft_strncmp(arr[i], "ss\n", 3) == 0)
			ss(a, b);
		else if (ft_strncmp(arr[i], "pa\n", 3) == 0)
			pa(a, b);
		else if (ft_strncmp(arr[i], "pb\n", 3) == 0)
			pb(a, b);
		else if (ft_strncmp(arr[i], "ra\n", 3) == 0)
			ra(a);
		else if (ft_strncmp(arr[i], "rb\n", 3) == 0)
			rb(b);
		else if (ft_strncmp(arr[i], "rr\n", 3) == 0)
			rr(a, b);
		else if (ft_strncmp(arr[i], "rra\n", 4) == 0)
			rra(a);
		else if (ft_strncmp(arr[i], "rrb\n", 4) == 0)
			rrb(b);
		else if (ft_strncmp(arr[i], "rrr\n", 4) == 0)
			rrr(a, b);
	}
}

int	validate(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr[i])
	{
		if (ft_strncmp(arr[i], "pb\n", 3) != 0 && ft_strncmp(arr[i], "pa\n",
				3) != 0 && ft_strncmp(arr[i], "sa\n", 3) != 0
			&& ft_strncmp(arr[i], "sb\n", 3) != 0 && ft_strncmp(arr[i], "ss\n",
				3) != 0 && ft_strncmp(arr[i], "ra\n", 3) != 0
			&& ft_strncmp(arr[i], "rb\n", 3) != 0 && ft_strncmp(arr[i], "rr\n",
				3) != 0 && ft_strncmp(arr[i], "rra\n", 4) != 0
			&& ft_strncmp(arr[i], "rrb\n", 4) != 0 && ft_strncmp(arr[i],
				"rrr\n", 4) != 0)
			return (0);
		i++;
	}
	return (1);
}

char	**read_input(void)
{
	char	**arr;
	char	*line;

	arr = NULL;
	line = get_next_line(0);
	while (line)
	{
		arr = ft_arrjoin(arr, line);
		ft_remove(line);
		line = get_next_line(0);
	}
	return (arr);
}

int	__continue(char **arr)
{
	if (arr)
	{
		push_swap_checker(get_head_a(), get_head_b(), arr, -1);
		if (is_sorted(*get_head_a()) && !(*get_head_b()))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else if (!is_sorted(*get_head_a()))
		return (ft_putstr("KO\n"), 1);
	else if (is_sorted(*get_head_a()) && !(*get_head_b()))
		return (ft_putstr("OK\n"), 0);
	else
		return (ft_puterror("Error\n"), 1);
	return (0);
}

int	main(int ac, char *av[])
{
	char	*res;
	char	**arr;
	int		exit;

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
		return (free_garb(), ft_puterror("Error\n"), 1);
	apply(arr);
	arr = read_input();
	if (!validate(arr))
		return (ft_puterror("Error\n"), free_garb(), 1);
	exit = __continue(arr);
	return (free_garb(), exit);
}
