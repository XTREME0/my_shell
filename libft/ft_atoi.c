/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:21:06 by ataai             #+#    #+#             */
/*   Updated: 2024/11/01 14:05:06 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	catch_of(int s)
{
	if (s == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			s;
	ssize_t		num;

	i = 0;
	s = 1;
	num = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (num > ((9223372036854775807 - (str[i] - '0')) / 10))
			return (catch_of(s));
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)num * s);
}
