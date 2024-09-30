/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_graphics_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:58:35 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 04:58:49 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 65307)
		shut_window(mlx);
	return (0);
}

void	selected_car_img_two(int car_code, t_mlx *mlx)
{
	if (car_code == 3)
	{
		mlx->car_rigth = "./img/car/mclaren/mclaren_rigth.xpm";
		mlx->car_left = "./img/car/mclaren/mclaren_left.xpm";
		mlx->car_up = "./img/car/mclaren/mclaren_up.xpm";
		mlx->car_down = "./img/car/mclaren/mclaren_down.xpm";
	}
	else if (car_code == 4)
	{
		mlx->car_rigth = "./img/car/ferrari/ferrari_rigth.xpm";
		mlx->car_left = "./img/car/ferrari/ferrari_left.xpm";
		mlx->car_up = "./img/car/ferrari/ferrari_up.xpm";
		mlx->car_down = "./img/car/ferrari/ferrari_down.xpm";
	}
	else if (car_code == 5)
	{
		mlx->car_rigth = "./img/car/aston/aston_rigth.xpm";
		mlx->car_left = "./img/car/aston/aston_left.xpm";
		mlx->car_up = "./img/car/aston/aston_up.xpm";
		mlx->car_down = "./img/car/aston/aston_down.xpm";
	}
}

void	selected_car_img(int car_code, t_mlx *mlx)
{	
	if (car_code == 1)
	{
		mlx->car_rigth = "./img/car/mustang/mustang_rigth.xpm";
		mlx->car_left = "./img/car/mustang/mustang_left.xpm";
		mlx->car_up = "./img/car/mustang/mustang_up.xpm";
		mlx->car_down = "./img/car/mustang/mustang_down.xpm";
	}
	else if (car_code == 2)
	{
		mlx->car_rigth = "./img/car/mustang_1/mustang_1_rigth.xpm";
		mlx->car_left = "./img/car/mustang_1/mustang_1_left.xpm";
		mlx->car_up = "./img/car/mustang_1/mustang_1_up.xpm";
		mlx->car_down = "./img/car/mustang_1/mustang_1_down.xpm";
	}
	else
		selected_car_img_two(car_code, mlx);
	second_end_mlx(mlx);
	game_screen(mlx);
}

int	get_car(int key, int x, int y, t_mlx *mlx)
{
	if (key == 1)
	{
		if ((x >= 42 && x <= 238) && (y >= 299 && y <= 429))
			selected_car_img(1, mlx);
		else if ((x >= 283 && x <= 504) && (y >= 302 && y <= 426))
			selected_car_img(2, mlx);
		else if ((x >= 532 && x <= 758) && (y >= 307 && y <= 420))
			selected_car_img(3, mlx);
		else if ((x >= 786 && x <= 1006) && (y >= 303 && y <= 424))
			selected_car_img(4, mlx);
		else if ((x >= 1071 && x <= 1256) && (y >= 295 && y <= 431))
			selected_car_img(5, mlx);
	}
	return (0);
}

void	second_screen(t_mlx *mlx)
{
	int		w;
	int		h;
	char	*choice;

	w = 1290;
	h = 726;
	choice = "./img/choice_screen.xpm";
	mlx->connection = mlx_init();
	mlx->window = mlx_new_window(mlx->connection, 1290, 726, "so_long");
	mlx->choice = mlx_xpm_file_to_image(mlx->connection, choice, &w, &h);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->choice, 0, 0);
	mlx_mouse_hook(mlx->window, get_car, mlx);
	mlx_hook(mlx->window, 17, 0, shut_window, mlx);
	mlx_hook(mlx->window, 2, 1L << 0, key_pressed, mlx);
	mlx_loop(mlx->connection);
}
