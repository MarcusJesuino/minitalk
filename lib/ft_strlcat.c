/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:52:12 by masantos          #+#    #+#             */
/*   Updated: 2025/07/22 19:52:12 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (n == 0)
		return (srclen);
	if (destlen >= n)
		return (n + srclen);
	else
	{
		i = 0;
		while ((destlen + i) < (n -1) && src[i])
		{
			dest[destlen + i] = src[i];
			i++;
		}
		dest[destlen + i] = '\0';
	}
	return (destlen + srclen);
}
