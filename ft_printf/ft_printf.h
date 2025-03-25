/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:49:57 by ariyad            #+#    #+#             */
/*   Updated: 2025/03/12 22:18:33 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putcharc(char c);
int		ft_putstring(char	*s);
int		nbr_handle(int n);
int		u_nbr_handle(unsigned int n);
int		hex_handle(char flag, unsigned int n);
int		addr_handle(void *ptr);
int		ft_printf(const char *format, ...);

#endif
