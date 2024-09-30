/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_graphics_extras.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:04:45 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 05:04:56 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	down_window(t_mlx *mlx)
{
	ultimate_end_mlx(mlx);
	end(3, mlx);
	return (0);
}

int	ked_pressed(int key, t_mlx *mlx)
{
	if (key == 65307)
		shut_window(mlx);
	return (0);
}

void	load_pointers_for_img(t_mlx *mlx, void *tmp)
{
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
	mlx->e = mlx_xpm_file_to_image(tmp, mlx->e_img, &mlx->d, &mlx->d);
	mlx->w = mlx_xpm_file_to_image(tmp, mlx->w_img, &mlx->d, &mlx->d);
	mlx->g = mlx_xpm_file_to_image(tmp, mlx->g_img, &mlx->d, &mlx->d);
	mlx->car = mlx_xpm_file_to_image(tmp, mlx->c_p, &mlx->img_w, &mlx->img_h);
	mlx->c = mlx_xpm_file_to_image(tmp, mlx->c_img, &mlx->d, &mlx->d);
	mlx->f = mlx_xpm_file_to_image(tmp, mlx->f_img, &mlx->d, &mlx->d);
}

void	second_end_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->connection, mlx->window);
	if (mlx->choice)
		mlx_destroy_image(mlx->connection, mlx->choice);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
}

int	shut_window(t_mlx *mlx)
{
	second_end_mlx(mlx);
	end(3, mlx);
	return (0);
}
