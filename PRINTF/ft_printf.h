/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:40:33 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/19 13:54:49 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
void	ft_putstr(char *string);
int		ft_putnbr(int number);
int		ft_puthex(int number, char base);
int		output_char(va_list arguments);
int		output_str(va_list arguments);
int		output_int(va_list arguments);
int		output_hexa(unsigned long number, char base);
int		output_pointer(va_list arguments);
int		output_unsigned_int(va_list arguments);

#endif
