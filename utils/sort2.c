/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:25:21 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/10 05:11:24 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_list *a, int index)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp->n);
		tmp = tmp->next;
	}
	return (0);
}

bool	is_n_up(t_list *b, int n)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = b;
	i = 0;
	size = ft_lstsize(b);
	while (tmp && i++ <= size / 2)
	{
		if (tmp->n == n)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	sort_four(t_list **a, t_list **b)
{
	int		n;
	bool	is_up;

	n = get_index(*a, 0);
	is_up = false;
	if (is_n_up(*a, n))
		is_up = true;
	if (is_up)
	{
		while ((*a)->n != n)
			ra(a, true);
	}
	else
	{
		while ((*a)->n != n)
			rra(a, true);
	}
	pb(a, b, true);
	sort_three(a);
	pa(a, b, true);
}

void	sort_five(t_list **a, t_list **b, int index)
{
	int		n;
	bool	is_up;

	n = get_index(*a, index);
	is_up = is_n_up(*a, n);
	while ((*a)->n != n)
	{
		if (is_up)
			ra(a, true);
		else
			rra(a, true);
	}
	pb(a, b, true);
	if (!index)
		sort_five(a, b, 1);
	sort_three(a);
	pa(a, b, true);
	pa(a, b, true);
}
