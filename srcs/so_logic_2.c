/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_logic_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:19:31 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 05:19:45 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	extend(t_mlx *mlx, void *car)
{
	mlx->c_p = car;
	mlx->moviments++;
	ft_printf("Moves: %d\n", mlx->moviments);
}

void	end_over(t_mlx *mlx)
{
	ft_printf("\033[35mGame Over :( !!\n\033[0m");
	ultimate_end_mlx(mlx);
	end(3, mlx);
}

int	end_game(char c, int colet)
{
	if (c == 'E' && colet == 0)
		return (1);
	else
		return (0);
}

void	end_message(t_mlx *mlx)
{
	ft_printf("\033[32mCONGRATULATIONS!! Game ended up!\n\033[0m");
	ultimate_end_mlx(mlx);
	end(3, mlx);
}

void	fd_verification(t_mlx *mlx, char ***matrix, int fd)
{
	int	k;

	k = 0;
	if (fd < 0)
	{
		perror("Error opening file");
		k = 0;
		while (k < mlx->lines)
		{
			free((*matrix)[k]);
			k++;
		}
		free(*matrix);
		exit(EXIT_FAILURE);
	}
}
