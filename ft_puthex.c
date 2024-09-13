/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:54:57 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/13 14:16:30 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long num)
{
	int	i;

	i = 0;
	if (num <= 0)
	{
		i++;
		num = -num;
	}
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static char	*hex_itoa(unsigned long num, const char capital)
{
	int			len;
	char		*num_hex;
	const char	*symbols;
	const char	*symbols_down;

	len = hex_len(num);
	symbols = "0123456789ABCDEF";
	symbols_down = "0123456789abcdef";
	num_hex = (char *)malloc(sizeof(char) * (len + 1));
	if (num_hex == NULL)
		return (NULL);
	else if (num == 0)
		num_hex[0] = '0';
	num_hex[len] = '\0';
	while (num)
	{
		if (capital == 'x')
			num_hex[--len] = symbols_down[num % 16];
		else if (capital == 'X')
			num_hex[--len] = symbols[num % 16];
		num = num / 16;
	}
	return (num_hex);
}

int	ft_puthex(unsigned long num, const char capital)
{
	int		len;
	char	*hex_num;

	len = 0;
	hex_num = hex_itoa(num, capital);
	len = ft_putstr(hex_num);
	free(hex_num);
	return (len);
}
/*
int	main(void)
{
	long int num1 = 123456789;
    long int num2 = -987654321;
    long int num3 = 0;

    // Hexadecimal de num1 (minúsculas):
    ft_puthex(num1, 'x');
    printf("\n");

    // Hexadecimal de num1 (mayúsculas):
    ft_puthex(num1, 'X');
    printf("\n");

	// Hexadecimal de num2 (minúsculas):
    ft_puthex(num2, 'x');
    printf("\n");

	// Hexadecimal de num2 (mayúsculas):
    ft_puthex(num2, 'X');
    printf("\n");

	// Hexadecimal de num3 (minúsculas):
    ft_puthex(num3, 'x');
    printf("\n");

	// Hexadecimal de num3 (mayúsculas):
    ft_puthex(num3, 'X');
    printf("\n");

    return (0);
}
*/
