/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:47:55 by ariyad            #+#    #+#             */
/*   Updated: 2025/03/12 22:19:29 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	exec_flag(char flag, va_list arg, int *count)
{
	if (flag == 's')
		*count += ft_putstring(va_arg(arg, char *));
	else if (flag == 'x' || flag == 'X')
		*count += hex_handle(flag, va_arg(arg, unsigned int));
	else if (flag == 'd' || flag == 'i')
		*count += nbr_handle(va_arg(arg, int));
	else if (flag == 'u')
		*count += u_nbr_handle(va_arg(arg, unsigned int));
	else if (flag == 'p')
		*count += addr_handle(va_arg(arg, void *));
	else if (flag == 'c')
	{
		ft_putcharc(va_arg(arg, int));
		*count += 1;
	}
	else
	{
		ft_putcharc(flag);
		*count += 1;
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (count);
			exec_flag(*format, arg, &count);
		}
		else
		{
			ft_putcharc(*format);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
