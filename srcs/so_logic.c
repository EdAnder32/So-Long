/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:17:03 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 09:46:00 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_up(t_mlx *mlx)
{
	if (mlx->copy[mlx->direction_y - 1][mlx->direction_x] != '1'
	&& mlx->rest_of_colet == 0)
	{
		mlx->direction_y -= 1;
		if (mlx->copy[mlx->direction_y - 1][mlx->direction_x] == 'N')
			end_over(mlx);
		extend(mlx, mlx->car_up);
		if (mlx->copy[mlx->direction_y][mlx->direction_x] == 'E')
			end_message(mlx);
	}
	if (mlx->copy[mlx->direction_y - 1][mlx->direction_x] != '1'
	&& mlx->copy[mlx->direction_y - 1][mlx->direction_x] != 'E'
	&& mlx->rest_of_colet != 0)
	{
		if (mlx->copy[mlx->direction_y - 1][mlx->direction_x] == 'C')
		{
			mlx->copy[mlx->direction_y - 1][mlx->direction_x] = '0';
			mlx->rest_of_colet--;
		}
		if (mlx->copy[mlx->direction_y - 1][mlx->direction_x] == 'N')
			end_over(mlx);
		mlx->direction_y -= 1;
		extend(mlx, mlx->car_up);
	}
}

void	move_down(t_mlx *mlx)
{
	if (mlx->copy[mlx->direction_y + 1][mlx->direction_x] != '1'
	&& mlx->rest_of_colet == 0)
	{
		if (mlx->copy[mlx->direction_y + 1][mlx->direction_x] == 'N')
			end_over(mlx);
		mlx->direction_y += 1;
		extend(mlx, mlx->car_down);
		if (mlx->copy[mlx->direction_y][mlx->direction_x] == 'E')
			end_message(mlx);
	}
	if (mlx->copy[mlx->direction_y + 1][mlx->direction_x] != '1'
	&& mlx->copy[mlx->direction_y + 1][mlx->direction_x] != 'E'
	&& mlx->rest_of_colet != 0)
	{
		if (mlx->copy[mlx->direction_y + 1][mlx->direction_x] == 'C')
		{
			mlx->copy[mlx->direction_y + 1][mlx->direction_x] = '0';
			mlx->rest_of_colet--;
		}
		if (mlx->copy[mlx->direction_y + 1][mlx->direction_x] == 'N')
			end_over(mlx);
		mlx->direction_y += 1;
		extend(mlx, mlx->car_down);
	}
}

void	move_rigth(t_mlx *mlx)
{
	if (mlx->copy[mlx->direction_y][mlx->direction_x + 1] != '1'
	&& mlx->rest_of_colet == 0)
	{
		if (mlx->copy[mlx->direction_y][mlx->direction_x + 1] == 'N')
			end_over(mlx);
		mlx->direction_x += 1;
		extend(mlx, mlx->car_rigth);
		if (mlx->copy[mlx->direction_y][mlx->direction_x] == 'E')
			end_message(mlx);
	}
	if (mlx->copy[mlx->direction_y][mlx->direction_x + 1] != '1'
	&& mlx->copy[mlx->direction_y][mlx->direction_x + 1] != 'E'
	&& mlx->rest_of_colet != 0)
	{
		if (mlx->copy[mlx->direction_y][mlx->direction_x + 1] == 'C')
		{
			mlx->copy[mlx->direction_y][mlx->direction_x + 1] = '0';
			mlx->rest_of_colet--;
		}
		if (mlx->copy[mlx->direction_y][mlx->direction_x + 1] == 'N')
			end_over(mlx);
		mlx->direction_x += 1;
		extend(mlx, mlx->car_rigth);
	}
}

void	move_left(t_mlx *mlx)
{
	if (mlx->rest_of_colet == 0
		&& mlx->copy[mlx->direction_y][mlx->direction_x - 1] != '1')
	{
		if (mlx->copy[mlx->direction_y][mlx->direction_x - 1] == 'N')
			end_over(mlx);
		mlx->direction_x -= 1;
		extend(mlx, mlx->car_left);
		if (mlx->copy[mlx->direction_y][mlx->direction_x] == 'E')
			end_message(mlx);
	}
	if (mlx->copy[mlx->direction_y][mlx->direction_x - 1] != '1'
	&& mlx->copy[mlx->direction_y][mlx->direction_x - 1] != 'E'
	&& mlx->rest_of_colet != 0)
	{
		if (mlx->copy[mlx->direction_y][mlx->direction_x - 1] == 'C')
		{
			mlx->copy[mlx->direction_y][mlx->direction_x - 1] = '0';
			mlx->rest_of_colet--;
		}
		if (mlx->copy[mlx->direction_y][mlx->direction_x - 1] == 'N')
			end_over(mlx);
		mlx->direction_x -= 1;
		extend(mlx, mlx->car_left);
	}
}

int	position(int key, t_mlx *mlx)
{
	if (key == 65307)
	{
		ultimate_end_mlx(mlx);
		end(3, mlx);
	}
	else if (key == 65362)
		move_up(mlx);
	else if (key == 65364)
		move_down(mlx);
	else if (key == 65363)
		move_rigth(mlx);
	else if (key == 65361)
		move_left(mlx);
	mounting_map(mlx);
	return (0);
}
