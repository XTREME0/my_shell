/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_nbr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:03 by ariyad            #+#    #+#             */
/*   Updated: 2025/03/12 22:19:46 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	nbr_len(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_put_u_nbr(unsigned int n)
{
	if (n > 9)
		ft_put_u_nbr(n / 10);
	ft_putcharc(n % 10 + 48);
}

int	u_nbr_handle(unsigned int n)
{
	ft_put_u_nbr(n);
	return (nbr_len(n));
}
