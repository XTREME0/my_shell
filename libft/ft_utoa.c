/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:18 by ataai             #+#    #+#             */
/*   Updated: 2025/04/08 16:04:47 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(unsigned long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill_str(char *str, size_t l, unsigned long num)
{
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[l--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	char		*str;
	size_t		l;

	l = num_len(n);
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	str[l--] = '\0';
	if (n != 0)
		str = fill_str(str, l, n);
	else
	{
		str[0] = '0';
		return (str);
	}
	return (str);
}
