/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_prnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:37:43 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 04:37:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_prnt(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (s == NULL)
		cnt += ft_putstr_prnt("(null)");
	else
	{
		while (s[i])
		{
			cnt += write(1, &s[i], 1);
			i++;
		}
	}
	return (cnt);
}
