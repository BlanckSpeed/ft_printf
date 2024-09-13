/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:54:44 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/13 12:29:59 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char letter)
{
	write(1, &letter, 1);
	return (1);
}
/*
int	main(void)
{
	char letter;
	
	letter = 'R';
	ft_putchar(letter);
	return (0);
}
*/