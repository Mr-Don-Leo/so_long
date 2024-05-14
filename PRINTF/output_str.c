/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:56:06 by mbabayan          #+#    #+#             */
/*   Updated: 2023/12/05 17:57:15 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_str(va_list arguments)
{
	int printed_count;
	char *string;

	string = va_arg(arguments, char *);
	printed_count = 0;
	if (string == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (string[printed_count])
	{
		ft_putchar(string[printed_count]);
		printed_count++;
	}
	return (printed_count);
}