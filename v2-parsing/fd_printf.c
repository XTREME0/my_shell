/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:39:31 by ataai             #+#    #+#             */
/*   Updated: 2025/04/15 15:21:24 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_printf(int fd, const char *format, ...)
{
	va_list	arg;

	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return ;
			ft_putstr_fd(fd, va_arg(arg, char *));
		}
		else
			ft_putchar_fd(fd, *format);
		format++;
	}
	va_end(arg);
}
