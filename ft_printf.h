/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:16:50 by quanguye          #+#    #+#             */
/*   Updated: 2024/09/13 14:59:18 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char letter);
int		ft_putnbr(int num);
int		ft_putstr(char *str);
int		ft_puthex(unsigned long num, const char capital);
int		ft_putptr(unsigned long pointer);
int		ft_putunsigned(unsigned int u_num);
char	*ft_itoa(int n);

#endif
