/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:56:06 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/19 13:53:02 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_str(va_list arguments)
{
	int		printed_count;
	char	*string;

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
