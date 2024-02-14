/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:59:19 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/12 07:01:49 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_in_up(t_list *b, int index)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = b;
	i = 0;
	size = ft_lstsize(b);
	while (tmp && i++ < size / 2)
	{
		if (tmp->index == index)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	innit_b(t_list **a, t_list **b)
{
	int		pivo1;
	int		pivo2;

	pivo2 = 0;
	while (ft_lstsize(*a) > 3)
	{
		pivo1 = (ft_lstsize(*a) / 6) + pivo2;
		pivo2 += ft_lstsize(*a) / 3;
		while (ft_lstsize(*b) < pivo2 && ft_lstsize(*a) > 3)
		{
			if (*b && (*a)->index >= pivo2 && (*b)->index < pivo1)
				rr(a, b, true);
			else if (*b && (*b)->index < pivo1)
				rb(b, true);
			if ((*a)->index >= pivo2)
				ra(a, true);
			else if ((*a)->index < pivo2)
				pb(a, b, true);
		}
	}
}

void	go_back_to_a(t_list **a, t_list	**b)
{
	int		max;

	max = ft_lstlast(*a)->index;
	while (ft_lstsize(*b) > 0)
	{
		if (*b && (*a)->index - 1 == (*b)->index)
			pa(a, b, true);
		else if (*b && (*a)->index - 1 == ft_lstlast(*b)->index)
			(1) && (rrb(b, true), pa(a, b, true));
		else if (ft_lstlast(*a)->index == max)
			(1) && (pa(a, b, true), ra(a, true));
		else if (*b && ft_lstlast(*a)->index < (*b)->index)
			(1) && (pa(a, b, true), ra(a, true));
		else if (*b && ft_lstlast(*a)->index < ft_lstlast(*b)->index)
			(1) && (rrb(b, true), pa(a, b, true), ra(a, true));
		else if ((*a)->index - 1 == ft_lstlast(*a)->index)
			rra(a, true);
		else if (*b && is_in_up(*b, (*a)->index - 1))
			rb(b, true);
		else
			rrb(b, true);
	}
}

void	sort_three(t_list **h)
{
	int	n[3];

	(1) && (n[0] = (*h)->index, n[1] = (*h)->next->index);
	n[2] = (*h)->next->next->index;
	if (n[1] < n[0] && n[1] < n[2] && n[0] < n[2])
		sa(h, true);
	else if (n[2] < n[1] && n[2] < n[0] && n[0] > n[1])
	{
		sa(h, true);
		rra(h, true);
	}
	else if (n[1] < n[0] && n[1] < n[2] && n[0] > n[2])
		ra(h, true);
	else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
	{
		sa(h, true);
		ra(h, true);
	}
	else if (n[2] < n[0] && n[2] < n[1] && n[0] < n[1])
		rra(h, true);
}

void	sort_low(t_list **a, t_list **b, int ac)
{
	if (ac == 2)
	{
		if ((*a)->index != 0)
			sa(a, true);
		my_exit(0, NULL, NULL, *a);
	}
	else if (ac == 3)
	{
		sort_three(a);
		my_exit(0, NULL, NULL, *a);
	}
	else if (ac == 4)
	{
		sort_four(a, b);
		my_exit(0, NULL, NULL, *a);
	}
	else if (ac == 5)
	{
		sort_five(a, b, 0);
		my_exit(0, NULL, NULL, *a);
	}
}
