/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:12:45 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 17:09:26 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx_a;
	size_t	idx_b;
	size_t	s_len;
	char	*s_join;

	idx_a = 0;
	idx_b = 0;
	s_len = ft_strlen(s1) + ft_strlen(s2);
	s_join = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!s_join)
		return (NULL);
	while (s1[idx_a])
		s_join[idx_b++] = s1[idx_a++];
	idx_a = 0;
	while (s2[idx_a])
		s_join[idx_b++] = s2[idx_a++];
	s_join[idx_b] = '\0';
	return (s_join);
}
