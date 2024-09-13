/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:12 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/13 14:28:38 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_pointer(unsigned long num)
{
	const char	*symbols;
	int			len;

	len = 0;
	symbols = "0123456789abcdef";
	if (num >= 16)
	{
		len += hex_pointer(num / 16);
		len += hex_pointer(num % 16);
	}
	else
		len += write(1, &symbols[num], 1);
	return (len);
}

int	ft_putptr(unsigned long pointer)
{
	int	len;

	len = 0;
	if (!pointer)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += hex_pointer(pointer);
	}
	return (len);
}
/*
int	main(void)
{
	unsigned long ptr1 = (unsigned long) &ptr1;  // Dirección de una variable
    unsigned long ptr2 = 0;  // Puntero nulo

    // Prueba con un puntero válido
    ft_putptr(ptr1);
    printf("\n");

    // Prueba con un puntero nulo
    ft_putptr(ptr2);
    printf("\n");

    return (0);
}
*/