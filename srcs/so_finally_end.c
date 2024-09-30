/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_finally_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:50:41 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 04:50:55 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_matrix(char **matrix)
{
	int	k;

	k = 0;
	while (matrix[k])
	{
		free(matrix[k]);
		k++;
	}
	free(matrix);
}

void	end_three(int n, t_mlx *mlx)
{
	if (n == 6 || n == 9)
	{
		ft_printf("Error\n! Found an unexpected character!\n");
		if (n == 6)
		{
			free_matrix(mlx->matrix);
			free_matrix(mlx->copy);
		}
		if (mlx)
			free(mlx);
		exit(0);
	}
	else if (n == 7)
	{
		ft_printf("Error\n! Empty Map!\n");
		free_matrix(mlx->matrix);
		free_matrix(mlx->copy);
		if (mlx)
			free(mlx);
		exit(0);
	}
}

void	end_two(int n, t_mlx *mlx)
{
	if (n == 4)
	{
		ft_printf("Error\n! Map must be surronded by walls\n");
		free_matrix(mlx->matrix);
		free_matrix(mlx->copy);
		if (mlx)
			free(mlx);
		exit(0);
	}
	else if (n == 5)
	{
		ft_printf("Error\n! Something is wrong in the map\n");
		ft_printf("Maybe is: Colet Number; Player; Exit Number\n");
		free_matrix(mlx->matrix);
		free_matrix(mlx->copy);
		if (mlx)
			free(mlx);
		exit(0);
	}
	else
		end_three(n, mlx);
}

void	end(int n, t_mlx *mlx)
{
	if (n == 1)
	{
		ft_printf("Error\n! Invalid File!\n");
		if (mlx)
			free(mlx);
		exit(0);
	}
	else if (n == 2)
	{
		ft_printf("Error\n! Invalid Map Length!\n");
		if (mlx)
			free(mlx);
		exit(0);
	}
	else if (n == 3)
	{
		free_matrix(mlx->matrix);
		free_matrix(mlx->copy);
		free(mlx);
		exit(0);
	}
	else
		end_two(n, mlx);
}

int	column_number(char *str, int fd, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		i++;
	if (str[i] == ' ' || str[i] == '\t')
	{
		free(str);
		close(fd);
		end(9, mlx);
	}
	return (i++);
}
