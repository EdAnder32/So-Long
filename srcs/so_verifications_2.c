/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_verifications_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:44:45 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 04:45:05 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	flood_fill(int x, int y, t_mlx *mlx)
{
	if (x < 0 || x >= mlx->columns || y < 0 || y >= mlx->lines)
		return ;
	if (mlx->matrix[y][x] == 'V')
		return ;
	if (mlx->matrix[y][x] == '1' || mlx->matrix[y][x] == 'E')
		return ;
	mlx->matrix[y][x] = 'V';
	flood_fill(x + 1, y, mlx);
	flood_fill(x - 1, y, mlx);
	flood_fill(x, y + 1, mlx);
	flood_fill(x, y - 1, mlx);
}

void	flood(int x, int y, t_mlx *mlx)
{
	if (x < 0 || x >= mlx->columns || y < 0 || y >= mlx->lines)
		return ;
	if (mlx->matrix[y][x] == 'F')
		return ;
	if (mlx->matrix[y][x] == '1')
		return ;
	mlx->matrix[y][x] = 'F';
	flood(x + 1, y, mlx);
	flood(x - 1, y, mlx);
	flood(x, y + 1, mlx);
	flood(x, y - 1, mlx);
}

void	finding_start_point(char **matrix, t_mlx *mlx, char c)
{
	int	k;
	int	x;

	k = 0;
	while (matrix[k])
	{
		x = 0;
		while (matrix[k][x])
		{
			if (matrix[k][x] == c)
			{
				mlx->x_start = x;
				mlx->y_start = k;
				return ;
			}
			x++;
		}
		k++;
	}
}

void	sending_to_flood_fill(t_mlx *mlx)
{
	finding_start_point(mlx->matrix, mlx, 'P');
	mlx->old_chr = 'P';
	flood_fill(mlx->x_start, mlx->y_start, mlx);
}

void	finish_that_stupid_verifications(t_mlx *mlx)
{
	see_matrix(mlx->matrix, mlx);
	sending_to_flood_fill(mlx);
	if (strchr_on_matrix(mlx->matrix, 'C') == 1)
	{
		ft_printf("ERROR\nImpossivel recolher todos coletaveis!\n");
		end(3, mlx);
	}
	if (strchr_on_matrix(mlx->matrix, 'P') == 1)
	{
		ft_printf("ERROR\nImpossivel se movimentar no mapa!\n");
		end(3, mlx);
	}
	finding_start_point(mlx->matrix, mlx, 'V');
	flood(mlx->x_start, mlx->y_start, mlx);
	if (strchr_on_matrix(mlx->matrix, 'E') == 1)
	{
		ft_printf("ERROR\nImpossivel Sair do mapa!\n");
		end(3, mlx);
	}
}
