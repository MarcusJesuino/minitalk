/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:37:20 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 18:57:36 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (!s1 && !s2)
		return (0);
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (s1);
}
