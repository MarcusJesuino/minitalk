/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 03:15:14 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 16:57:22 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;
	int		i;

	nbr = (long)n;
	len = ft_countdigits(nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = 45;
	return (str);
}
