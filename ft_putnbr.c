/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:05 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/13 13:56:01 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int		len;
	char	*snum;

	len = 0;
	snum = ft_itoa(num);
	len = ft_putstr(snum);
	free(snum);
	return (len);
}
/*
int	main(void)
{
	int	num;
	
	num = 42;
	ft_putnbr(num);
}
*/