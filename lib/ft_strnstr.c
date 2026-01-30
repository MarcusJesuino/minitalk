/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:38:40 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 17:07:13 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	ida;
	size_t	idb;

	ida = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (ida < n && str[ida])
	{
		idb = 0;
		while (to_find[idb] && (str[ida + idb] == to_find[idb])
			&& ((ida + idb) < n))
		{
			idb++;
			if (to_find[idb] == '\0')
				return ((char *)&str[ida]);
		}
		ida++;
	}
	return (NULL);
}
