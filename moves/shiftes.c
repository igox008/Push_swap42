/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:46 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/09 08:56:23 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b, bool prnt)
{
	ra(stack_a, false);
	rb(stack_b, false);
	if (prnt)
		ft_printf("rr\n");
}

t_list	*ft_lstprev(t_list **head)
{
	t_list	*cur;
	t_list	*prev;

	cur = *head;
	prev = NULL;
	if (head != NULL && *head != NULL)
	{
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return (prev);
}

int	rra(t_list **stack_a, bool prnt)
{
	t_list	*tmp;
	t_list	*prev;

	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = ft_lstlast(*stack_a);
		prev = ft_lstprev(stack_a);
		ft_lstadd_front(stack_a, tmp);
		prev->next = NULL;
		if (prnt)
			ft_printf("rra\n");
		return (0);
	}
	return (1);
}

int	rrb(t_list **stack_b, bool prnt)
{
	t_list	*tmp;
	t_list	*prev;

	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp = ft_lstlast(*stack_b);
		prev = ft_lstprev(stack_b);
		ft_lstadd_front(stack_b, tmp);
		prev->next = NULL;
		if (prnt)
			ft_printf("rrb\n");
		return (0);
	}
	return (1);
}

void	rrr(t_list **stack_a, t_list **stack_b, bool prnt)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	if (prnt)
		ft_printf("rrr\n");
}
