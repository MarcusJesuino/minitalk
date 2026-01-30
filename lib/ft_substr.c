/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:27:50 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 17:04:11 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx_a;
	size_t	idx_b;
	char	*sub_s;
	size_t	s_len;

	idx_a = start;
	idx_b = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	while (idx_b < len)
	{
		sub_s[idx_b] = s[idx_a];
		idx_b++;
		idx_a++;
	}
	sub_s[idx_b] = '\0';
	return (sub_s);
}
