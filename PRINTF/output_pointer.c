/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:46:32 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/19 13:54:06 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointer(size_t pointer, char *hex_base)
{
	int	c;

	c = 0;
	if (pointer >= 16)
		c += putpointer(pointer / 16, hex_base);
	ft_putchar(hex_base[pointer % 16]);
	c++;
	return (c);
}

int	output_pointer(va_list arguments)
{
	int		count;
	size_t	pointer;

	pointer = va_arg(arguments, size_t);
	ft_putstr("0x");
	count = output_hexa(pointer, 'x');
	return (count + 2);
}
