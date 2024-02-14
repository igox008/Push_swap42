/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:50:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/11 18:40:40 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

t_moves	*ft_lastmove(t_moves *lst)
{
	t_moves	*ptr;

	ptr = lst;
	if (ptr == NULL)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

t_moves	*ft_newmove(char *s)
{
	t_moves	*new;

	new = (t_moves *)malloc(sizeof(t_moves));
	if (new == NULL)
		return (NULL);
	new->move = s;
	new->next = NULL;
	return (new);
}

void	ft_addmove(t_moves **h, t_moves *new_m)
{
	t_moves	*ptr;

	ptr = ft_lastmove(*h);
	if (*h == NULL)
		*h = new_m;
	else
		ptr->next = new_m;
}

void	ft_move_clear(t_moves **m)
{
	t_moves	*ptr;
	t_moves	*tmp;

	if (m)
	{
		tmp = *m;
		while (tmp != NULL)
		{
			ptr = tmp->next;
			free(tmp->move);
			free(tmp);
			tmp = ptr;
		}
		*m = NULL;
	}
}

void	free_and_exit(t_list **a, t_list **b, char *s)
{
	ft_lstclear(b, NULL);
	ft_printf("%s\n", s);
	my_exit(0, NULL, NULL, *a);
}
