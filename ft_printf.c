/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuellar <lcuellar@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:09:14 by lcuellar          #+#    #+#             */
/*   Updated: 2023/10/31 14:11:33 by lcuellar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_arg(char c, va_list args)
//read the format and call the corresponding function
{
	int	var;

	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
	{
		var = va_arg(args, int);
		return (write(1, &var, 1));
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_put_p(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(char const *string, ...)
{
	va_list		args;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			count += ft_read_arg(string[i + 1], args);
			i++;
		}
		else
			count += write(1, &string[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
