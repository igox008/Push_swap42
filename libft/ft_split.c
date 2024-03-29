/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:14:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 06:04:14 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_w(char const *s, char *c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (is_in(s[i], c))
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] && !is_in(s[i], c))
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(n + 1);
	if (!new)
		return (NULL);
	while (i < n)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**ft_arr_fail(char **arr, int index)
{
	while (index >= 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char *c)
{
	int		i;
	int		index;
	int		wc;
	char	**arr;

	wc = count_w(s, c);
	index = -1;
	arr = (char **)malloc((sizeof(char *)) * (wc + 1));
	if (!arr)
		return (NULL);
	while (++index < wc)
	{
		i = 0;
		while (*s && is_in(*s, c))
			s++;
		while (*(s + i) && !is_in(*(s + i), c))
			i++;
		arr[index] = ft_strndup(s, i);
		if (arr[index] == NULL)
			return (ft_arr_fail(arr, index));
		while (*s && !is_in(*s, c))
			s++;
	}
	arr[index] = NULL;
	return (arr);
}
