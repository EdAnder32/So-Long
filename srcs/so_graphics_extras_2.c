/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_graphics_extras_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:08:24 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 05:08:39 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	set_images_and_dimentions(t_mlx *mlx)
{
	mlx->w_img = "./img/wall.xpm";
	mlx->c_img = "./img/colet.xpm";
	mlx->g_img = "./img/ground.xpm";
	mlx->f_img = "./img/finish.xpm";
	mlx->d = 50;
	mlx->e_img = "./img/enemy/enemy_1.xpm";
}

void	ultimate_end_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->connection, mlx->window);
	if (mlx->e)
		mlx_destroy_image(mlx->connection, mlx->e);
	if (mlx->w)
		mlx_destroy_image(mlx->connection, mlx->w);
	if (mlx->g)
		mlx_destroy_image(mlx->connection, mlx->g);
	if (mlx->car)
		mlx_destroy_image(mlx->connection, mlx->car);
	if (mlx->c)
		mlx_destroy_image(mlx->connection, mlx->c);
	if (mlx->f)
		mlx_destroy_image(mlx->connection, mlx->f);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
}

void	set_initial_value(t_mlx *mlx)
{
	mlx->e = NULL;
	mlx->w = NULL;
	mlx->g = NULL;
	mlx->car = NULL;
	mlx->c = NULL;
	mlx->f = NULL;
}

int	strchr_on_matrix(char **matrix, char c)
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
				return (1);
			x++;
		}
		k++;
	}
	return (0);
}

void	see_matrix(char **matrix, t_mlx *mlx)
{
	int	k;
	int	x;

	k = 0;
	while (matrix[k])
	{
		x = 0;
		while (matrix[k][x])
		{
			if (matrix[k][x] != 'C' && matrix[k][x] != '0'
			&& matrix[k][x] != '1' && matrix[k][x] != 'P'
			&& matrix[k][x] != 'E')
				end(6, mlx);
			x++;
		}
		k++;
	}
}
