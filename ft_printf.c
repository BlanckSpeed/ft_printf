/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:59 by quanguye          #+#    #+#             */
/*   Updated: 2024/09/11 19:22:02 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_specifier(const char *specifier, va_list args)
{
	int	length;

	length = 0;
	if (*specifier == 'd' || *specifier == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (*specifier == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (*specifier == 'x' || *specifier == 'X')
		length += ft_puthex((long)va_arg(args, unsigned int), *specifier);
	else if (*specifier == 'p')
		length += ft_putptr(va_arg(args, unsigned long));
	else if (*specifier == 'u')
		length += ft_putunsigned(va_arg(args, unsigned int));
	else if (*specifier == '%')
		length += write(1, "%", 1);
	else if (*specifier == 'c')
		length += ft_putchar(va_arg(args, int));
	else
		length += write(1, specifier, 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_length;

	total_length = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			total_length += handle_format_specifier(format, args);
		}
		else
		{
			write(1, format, 1);
			total_length++;
		}
		format++;
	}
	va_end(args);
	return (total_length);
}
/*
int main(void)
{
	int num = -20;
	char *str = "Hello :D";
	char *ptr = str;
	
	ft_printf("num: %d\nstr: %s\nptr: %p\n\n", num, str, ptr);
	printf("num: %d\nstr:%s\nptr:%p\n",num, str, ptr);
	return 0;
}
*/
