/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:19 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/13 14:40:33 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	if (*str == '\0')
		return (0);
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	char *str = "HOlA :D A TODOS EN 42\n";
	ft_putstr(str);
	
	return (0);
}
*/