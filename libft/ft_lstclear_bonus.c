/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:16:19 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 13:09:17 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	(void)del;
	if (lst)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			ptr = tmp->next;
			free(tmp);
			tmp = ptr;
		}
		*lst = NULL;
	}
}
