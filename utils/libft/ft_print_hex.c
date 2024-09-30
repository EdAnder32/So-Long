/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:00:58 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/31 14:26:06 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(unsigned int n)
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

void	ft_print(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_print(n / 16, format);
		ft_print(n % 16, format);
	}
	else
	{
		if (n <= 9)
		{
			ft_print_chr(n + '0');
		}
		else
		{
			if (format == 'x')
				ft_print_chr(n - 10 + 'a');
			if (format == 'X')
				ft_print_chr(n - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int i, const char format)
{
	if (i == 0)
		return (write(1, "0", 1));
	else
		ft_print(i, format);
	return (ft_size(i));
}
