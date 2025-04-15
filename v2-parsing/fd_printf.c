#include "parser.h"

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
			ft_pustr_fd(fd, va_arg(arg, char *));
		}
		else
			ft_putchar_fd(fd, *format);
		format++;
	}
	va_end(arg);
}
