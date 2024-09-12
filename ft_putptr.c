/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:12 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/11 19:23:33 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer(unsigned long num)
{
	const char	*s;
	int			i;

	i = 0;
	s = "0123456789abcdef";
	if (num >= 16)
	{
		i += ft_pointer(num / 16);
		i += ft_pointer(num % 16);
	}
	else
		i += write(1, &s[num], 1);
	return (i);
}

int	ft_putptr(unsigned long pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		i += write(1, "(nil)", 5);
	else
	{
		i += write(1, "0x", 2);
		i += ft_pointer(pointer);
	}
	return (i);
}
