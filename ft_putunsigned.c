/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:28 by rlendine          #+#    #+#             */
/*   Updated: 2024/09/13 15:11:39 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	itoa_len(long long num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len++;
		num = -num;
	}
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	long long		num;
	int				len;

	num = n;
	len = itoa_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	else if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int u_num)
{
	int		len;
	char	*str_num;

	len = 0;
	if (u_num == 0)
		len += write(1, "0", 1);
	else
	{
		str_num = ft_uitoa(u_num);
		len += ft_putstr(str_num);
		free(str_num);
	}
	return (len);
}
/*
int	main(void)
{
	unsigned int test1 = 42;
	unsigned int test2 = 0;
	unsigned int test3 = 123456789;

	// Prueba con el número 42
	printf("Output length: %d\n", ft_putunsigned(test1));

	// Prueba con el número 0
	printf("Output length: %d\n", ft_putunsigned(test2));

	// Prueba con el número 123456789
	printf("Output length: %d\n", ft_putunsigned(test3));

	return (0);
}
*/