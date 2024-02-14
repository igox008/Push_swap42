/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:09:54 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/06 21:07:23 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	t = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(t + 1);
	if (new == NULL)
		return (NULL);
	while (j < ft_strlen(s1))
		new[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
