/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:53:50 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 04:54:03 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	first_end_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->connection, mlx->window);
	if (mlx->i7)
		mlx_destroy_image(mlx->connection, mlx->i7);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
}

int	close_window(t_mlx *mlx)
{
	first_end_mlx(mlx);
	end(3, mlx);
	return (0);
}

int	ke_pressed(int key, t_mlx *mlx)
{
	if (key == 65307)
		close_window(mlx);
	return (0);
}

int	first_screen(int key, t_mlx *mlx)
{
	if (key == 65293)
	{
		first_end_mlx(mlx);
		second_screen(mlx);
	}
	return (0);
}

void	init_game(t_mlx *mlx)
{
	int		i_w;
	int		i_h;
	char	*i7;

	i_w = 1290;
	i_h = 726;
	mlx->player_x = 200;
	mlx->player_y = 200;
	i7 = "./img/initial/7.xpm";
	set_images_and_dimentions(mlx);
	mlx->width = mlx->columns * 50;
	mlx->heigth = mlx->lines * 50;
	mlx->connection = mlx_init();
	mlx->window = mlx_new_window(mlx->connection, 1290, 726, "so_long");
	mlx->i7 = mlx_xpm_file_to_image(mlx->connection, i7, &i_w, &i_h);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->i7, 0, 0);
	mlx_key_hook(mlx->window, ke_pressed, mlx);
	mlx_hook(mlx->window, 2, 1L << 0, first_screen, mlx);
	mlx_hook(mlx->window, 17, 0, close_window, mlx);
	mlx_loop(mlx->connection);
}
