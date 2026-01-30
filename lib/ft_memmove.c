/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:39:11 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 19:46:15 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	if (!s1 && !s2)
		return (0);
	i = 0;
	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (dst > src)
	{
		while (n--)
			dst[n] = src[n];
	}
	else
	{
		while (i < n)
		{
			dst [i] = src[i];
			i++;
		}
	}
	return (s1);
}
