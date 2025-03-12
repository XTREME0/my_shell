/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:48:16 by ariyad            #+#    #+#             */
/*   Updated: 2025/03/12 22:19:34 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int n, char *base, int	*count)
{
	if (n > 15)
		ft_puthex(n / 16, base, count);
	ft_putcharc(base[n % 16]);
	*count += 1;
}

int	hex_handle(char flag, unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	if (flag == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_puthex(n, base, &count);
	return (count);
}
