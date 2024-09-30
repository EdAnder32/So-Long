/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:18:29 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/31 20:18:33 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_process_specifier(char c, va_list list)
{
	if (c == 's')
		return (ft_print_str(va_arg(list, char *)));
	else if (c == 'c')
		return (ft_print_chr(va_arg(list, int)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(list, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(list, long int), c));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(list, void *)));
	else if (c == 'u')
		return (ft_print_nbr_u(va_arg(list, unsigned int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		contador;

	i = 0;
	contador = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			contador += ft_process_specifier(format[i], list);
		}
		else
		{
			write (1, &format[i], 1);
			contador++;
		}
		i++;
	}
	va_end(list);
	return (contador);
}
