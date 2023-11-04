/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuellar <lcuellar@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:19:47 by lcuellar          #+#    #+#             */
/*   Updated: 2023/11/04 22:37:51 by lcuellar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned long n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_u(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	count++;
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_hex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_putnbr_hex(n / 16, base);
	write(1, &base[n % 16], 1);
	count++;
	return (count);
}

int	ft_put_p(unsigned long n)
{
	char	str[16];
	int		i;
	int		count;

	if (n == 0)
		return (ft_putstr("0x0"));
	count = ft_putstr("0x");
	ft_bzero(str, 16);
	i = 0;
	while (n)
	{
		str[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i--)
		count += write(1, &str[i], 1);
	return (count);
}

int	ft_putnbr(int nb)
{
	int		len;
	char	*n;

	len = 0;
	n = ft_itoa(nb);
	len += ft_putstr(n);
	free(n);
	return (len);
}
