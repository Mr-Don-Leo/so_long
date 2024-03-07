/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:27:30 by mbabayan          #+#    #+#             */
/*   Updated: 2023/12/05 18:27:35 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_hexa(unsigned long number, char base)
{
	int		count;
	char	*hex;

	count = 0;
	if (base == 'X')
		hex = "0123456789ABCDEF";
	if (base == 'x')
		hex = "0123456789abcdef";
	if (number > 15)
		count += output_hexa(number / 16, base);
	count += ft_putchar(hex[number % 16]);
	return (count);
}
