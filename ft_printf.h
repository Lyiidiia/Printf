/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuellar <lcuellar@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:15 by lcuellar          #+#    #+#             */
/*   Updated: 2023/11/04 23:17:33 by lcuellar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(char const *string, ...);
int		ft_read_arg(char c, va_list args);
int		ft_putstr(char *s);
int		ft_put_p(unsigned long n);
int		ft_putnbr(int nb);
int		ft_putnbr_u(unsigned long n);
int		ft_putnbr_hex(unsigned int n, char *base);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);

#endif