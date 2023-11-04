/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuellar <lcuellar@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:01:45 by lcuellar          #+#    #+#             */
/*   Updated: 2023/11/04 22:37:56 by lcuellar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
		*str++ = '\0';
}

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_fillstr(char *str, int n, int len)
{
	long	n2;

	n2 = (long)n;
	str[len] = '\0';
	len--;
	if (n2 < 0)
	{
		str[0] = '-';
		n2 = -n2;
	}
	if (n2 == 0)
		str[0] = '0';
	while (n2 > 0)
	{
		str[len] = (n2 % 10) + '0';
		n2 = n2 / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_fillstr(str, n, len);
	return (str);
}
