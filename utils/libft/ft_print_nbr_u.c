/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:09:13 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/31 17:16:30 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr_u(unsigned int n)
{
	char	nbr;
	int		contador;

	contador = 0;
	if (n == 0)
		return (ft_print_chr('0'));
	if (n > 9)
		contador += ft_print_nbr_u(n / 10);
	nbr = (n % 10) + '0';
	contador += ft_print_chr(nbr);
	return (contador);
}
