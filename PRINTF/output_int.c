/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:41:45 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/19 13:54:18 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_int(va_list arguments)
{
	int	printed_count;
	int	number;

	number = va_arg(arguments, int);
	printed_count = ft_putnbr(number);
	return (printed_count);
}
