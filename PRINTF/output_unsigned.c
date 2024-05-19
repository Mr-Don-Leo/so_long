/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:59:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/19 13:53:21 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunbr(size_t number)
{
	int	printed_count;

	printed_count = 1;
	if (number > 9)
		printed_count += putunbr(number / 10);
	ft_putchar(number % 10 + '0');
	return (printed_count);
}

int	output_unsigned_int(va_list arguments)
{
	unsigned int	number;
	int				printed_count;

	number = va_arg(arguments, unsigned int);
	printed_count = putunbr(number);
	return (printed_count);
}
