/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:48:10 by ariyad            #+#    #+#             */
/*   Updated: 2025/03/12 22:19:18 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddr(size_t addr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (addr > 15)
		ft_putaddr(addr / 16, count);
	ft_putcharc(base[addr % 16]);
	*count += 1;
}

int	addr_handle(void *ptr)
{
	int		count;
	size_t	addr;

	count = 2;
	addr = (size_t)ptr;
	write(1, "0x", 2);
	ft_putaddr(addr, &count);
	return (count);
}
