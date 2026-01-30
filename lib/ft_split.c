/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:55:00 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 17:00:25 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		idx_a;
	int		idx_b;
	int		start;
	char	**splited;

	idx_a = 0;
	idx_b = 0;
	splited = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!splited)
		return (NULL);
	while (s[idx_a])
	{
		while (s[idx_a] && s[idx_a] == c)
			idx_a++;
		start = idx_a;
		while (s[idx_a] && s[idx_a] != c)
			idx_a++;
		if (idx_a > start)
			splited[idx_b++] = ft_substr(s, start, idx_a - start);
	}
	splited[idx_b] = NULL;
	return (splited);
}
