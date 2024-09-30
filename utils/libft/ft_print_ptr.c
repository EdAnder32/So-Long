/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:07:08 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/31 16:43:45 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizer(unsigned long n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	ft_printers(unsigned long n)
{
	if (n >= 16)
	{
		ft_printers(n / 16);
		ft_printers(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_print_chr(n + '0');
		else
			ft_print_chr(n - 10 + 'a');
	}
}

static int	ft_print_hexas(unsigned long i)
{
	if (i == 0)
		return (write(1, "0", 1));
	else
		ft_printers(i);
	return (ft_sizer(i));
}

int	ft_print_ptr(void *i)
{
	int	contador;

	contador = 0;
	if (!i)
	{
		contador += ft_print_str("(nil)");
		return (contador);
	}
	contador = 2;
	write(1, "0x", 2);
	contador += ft_print_hexas((unsigned long)i);
	return (contador);
}
