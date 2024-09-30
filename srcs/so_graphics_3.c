/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_graphics_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:02:05 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 05:02:27 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	im_tired(t_mlx *mlx, int k, int x, void	*tmp)
{
	if (mlx->copy[k][x] == '1')
		mlx_put_image_to_window(tmp, mlx->window, mlx->w, mlx->x, mlx->y);
	if (mlx->copy[k][x] == '0'
	|| (mlx->copy[k][x] == 'P' && (k != mlx->direction_y
	|| x != mlx->direction_x)))
		mlx_put_image_to_window(tmp, mlx->window, mlx->g, mlx->x, mlx->y);
	if (mlx->copy[k][x] != '1')
	{
		if (k == mlx->direction_y && x == mlx->direction_x)
		{
			mlx_put_image_to_window(tmp, mlx->window, mlx->car, mlx->x, mlx->y);
			mlx->copy[k][x] = 'P';
		}
	}
	if (mlx->copy[k][x] == 'C')
		mlx_put_image_to_window(tmp, mlx->window, mlx->c, mlx->x, mlx->y);
	if (mlx->copy[k][x] == 'E')
		mlx_put_image_to_window(tmp, mlx->window, mlx->f, mlx->x, mlx->y);
	if (mlx->copy[k][x] == 'N')
		mlx_put_image_to_window(tmp, mlx->window, mlx->e, mlx->x, mlx->y);
}

void	draw_things_on_screen(t_mlx *mlx, void	*tmp)
{
	int		k;
	int		x;

	k = 0;
	while (mlx->copy[k])
	{
		x = 0;
		mlx->x = 0;
		while (mlx->copy[k][x])
		{
			im_tired(mlx, k, x, tmp);
			mlx->x += 50;
			x++;
		}
		mlx->y += 50;
		k++;
	}	
}

void	mounting_map(t_mlx *mlx)
{
	void	*tmp;

	tmp = mlx->connection;
	load_pointers_for_img(mlx, tmp);
	mlx->y = 0;
	draw_things_on_screen(mlx, tmp);
}

void	first_position_for_car(t_mlx *mlx)
{
	int	k;
	int	x;

	k = 0;
	mlx->rest_of_colet = 0;
	while (mlx->copy[k])
	{
		x = 0;
		while (mlx->copy[k][x])
		{
			if (mlx->copy[k][x] == 'P')
			{
				mlx->direction_y = k;
				mlx->direction_x = x;
			}
			if (mlx->copy[k][x] == 'C')
				mlx->rest_of_colet++;
			x++;
		}
		k++;
	}
}

void	game_screen(t_mlx *mlx)
{
	void	*tmp;

	mlx->img_w = 100;
	mlx->img_h = 50;
	if ((mlx->width > 1920) || (mlx->heigth > 1080))
	{
		ft_printf("Error\nMapa demasiado grande!\n");
		end(3, mlx);
	}
	mlx->connection = mlx_init();
	tmp = mlx->connection;
	mlx->window = mlx_new_window(tmp, mlx->width, mlx->heigth, "so_long");
	mlx->x = 0;
	mlx->y = 0;
	mlx->car_x = 0;
	mlx->car_y = 0;
	mlx->times = 0;
	mlx->moviments = 0;
	first_position_for_car(mlx);
	mlx->c_p = mlx->car_up;
	set_initial_value(mlx);
	mounting_map(mlx);
	mlx_hook(mlx->window, 17, 0, down_window, mlx);
	mlx_hook(mlx->window, 2, 1L << 0, position, mlx);
	mlx_loop(mlx->connection);
}
