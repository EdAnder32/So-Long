/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:44:33 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/28 19:14:09 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	define(int *vars)
{
	if (vars[2] == 0)
	{
		vars[0] = 0;
		vars[1] = 0;
		vars[2] = 1;
	}
}

static	int	ler_buffer(int fd, char *chr, int *buffer_size, int *buffer_pos)
{
	*buffer_size = read(fd, chr, BUFFER_SIZE);
	*buffer_pos = 0;
	return (*buffer_size);
}

char	*get_next_line(int fd)
{
	static char	cont[BUFFER_SIZE];
	char		str[7000000];
	static int	n[3];
	int			i;

	define(n);
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (n[0] >= n[1])
			if (ler_buffer(fd, cont, &n[1], &n[0]) <= 0)
				break ;
		str[i++] = cont[n[0]++];
		if (str[i - 1] == '\n')
			break ;
	}
	str[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(str));
}
