/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 06:03:49 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/09 08:55:27 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	get_lowest(t_list *h)
{
	t_list	*tmp;
	int		n;

	tmp = h;
	n = INT_MAX;
	while (tmp)
	{
		if (tmp->n <= n)
			n = tmp->n;
		tmp = tmp->next;
	}
	return (n);
}

int	next_lowest(t_list *h, int low)
{
	t_list	*tmp;
	int		n;

	tmp = h;
	n = INT_MAX;
	while (h)
	{
		if (h->n > low && h->n < n && h->index == -1)
			n = h->n;
		h = h->next;
	}
	return (n);
}

void	give_it_index(t_list **h, int *index, int low)
{
	t_list	*tmp;

	tmp = *h;
	while (tmp)
	{
		if (tmp->n == low)
		{
			tmp->index = *index;
			(*index)++;
			break ;
		}
		tmp = tmp->next;
	}
}

void	index_it(t_list **head)
{
	t_list	*h;
	t_list	*tmp;
	int		n[2];

	(1) && (h = *head, tmp = *head, n[1] = 0);
	n[0] = get_lowest(*head);
	while (h)
	{
		give_it_index(head, &n[1], n[0]);
		n[0] = next_lowest(tmp, n[0]);
		h = h->next;
	}
}

int	check_sorted(t_list *h)
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = h;
	if (tmp && tmp->next != NULL)
	{
		nxt = tmp->next;
		while (tmp && nxt)
		{
			if (tmp->index > nxt->index)
				return (1);
			tmp = tmp->next;
			nxt = nxt->next;
		}
	}
	return (0);
}
