/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:36 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/30 15:51:14 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	int		contador;

	contador = 0;
	if (n == 0)
		return (ft_print_chr('0'));
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		contador += ft_print_chr('-');
		n = -n;
	}
	if (n > 9)
		contador += ft_print_nbr(n / 10);
	contador += ft_print_chr((n % 10) + '0');
	return (contador);
}
