/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_verifications_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:47:39 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 04:47:54 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	now_other(t_mlx *mlx)
{
	int	k;
	int	x;

	k = 0;
	while (mlx->matrix[k])
	{
		x = 0;
		while (mlx->matrix[k][x])
		{
			if (mlx->matrix[k][x] == 'C')
				mlx->rest_of_colet++;
			if (mlx->matrix[k][x] == 'E')
				mlx->output++;
			if (mlx->matrix[k][x] == 'P')
				mlx->playerr++;
			x++;
		}
		k++;
	}
	if (mlx->rest_of_colet == 0 || mlx->output != 1 || mlx->playerr != 1)
		end(5, mlx);
}

void	matrix_existence(t_mlx *mlx)
{
	if (mlx->matrix[0] == NULL)
		end(7, mlx);
}

void	wall_verification_and_other(t_mlx *mlx)
{
	int	k;
	int	last_line;
	int	last_col;

	mlx->rest_of_colet = 0;
	mlx->output = 0;
	mlx->playerr = 0;
	last_line = mlx->lines - 1;
	last_col = mlx->columns - 1;
	k = 0;
	matrix_existence(mlx);
	while (k <= last_col)
	{
		if (mlx->matrix[0][k] != '1' || mlx->matrix[last_line][k] != '1')
			end(4, mlx);
		k++;
	}
	k = 0;
	while (k <= last_line)
	{
		if (mlx->matrix[k][0] != '1' || mlx->matrix[k][last_col] != '1')
			end(4, mlx);
		k++;
	}
	now_other(mlx);
}

void	verificate_extension(char *str, t_mlx *mlx)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == 'b')
			{
				i++;
				if (str[i] == 'e')
				{
					i++;
					if (str[i] == 'r')
						flag = 1;
				}
			}
		}
		i++;
	}
	if (flag != 1)
		end (1, mlx);
}
