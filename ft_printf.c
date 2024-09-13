/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:59 by quanguye          #+#    #+#             */
/*   Updated: 2024/09/13 13:40:18 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_specifier(const char *specifier, va_list args)
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
	va_list	args_storage;
	int		total_length;

	total_length = 0;
	va_start(args_storage, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			total_length += format_specifier(format, args_storage);
		}
		else
		{
			write(1, format, 1);
			total_length++;
		}
		format++;
	}
	va_end(args_storage);
	return (total_length);
}
/*
int	main(void)
{
	int num = -20;
	char *str = "Hello :D";
	char *ptr = str;
	unsigned int u_num = 42;
	char letter = 'A';
	int hex_num = -987654321;

	// Test %d and %i
	ft_printf("ft_printf - num(%%d): %d\n", num);
	printf("printf    - num(%%d): %d\n", num);
	ft_printf("ft_printf - num(%%i): %i\n", num);
	printf("printf    - num(%%i): %i\n\n", num);

	// Test %s
	ft_printf("ft_printf - str(%%s): %s\n", str);
	printf("printf    - str(%%s): %s\n\n", str);

	// Test %p
	ft_printf("ft_printf - ptr(%%p): %p\n", ptr);
	printf("printf    - ptr(%%p): %p\n\n", ptr);

	// Test %u
	ft_printf("ft_printf - unsigned num(%%u): %u\n", u_num);
	printf("printf    - unsigned num(%%u): %u\n\n", u_num);

	// Test %c
	ft_printf("ft_printf - char(%%c): %c\n", letter);
	printf("printf    - char(%%c): %c\n\n", letter);

	// Test %x and %X
	ft_printf("ft_printf - hex (%%x): %x\n", hex_num);
	printf("printf    - hex (%%x): %x\n", hex_num);
	ft_printf("ft_printf - hex (%%X): %X\n", hex_num);
	printf("printf    - hex (%%X): %X\n\n", hex_num);

	// Test %%
	ft_printf("ft_printf - percent(%%): %%\n");
	printf("printf    - percent(%%): %%\n");

	return (0);
}
*/