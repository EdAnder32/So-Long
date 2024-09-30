/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_verifications.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:41:01 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/14 04:41:24 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	passing(t_mlx *mlx, char ***matrix, int fd)
{
	char	*line;
	int		k;

	k = 0;
	while (k < mlx->lines)
	{
		line = get_next_line(fd);
		if (!line)
		{
			while (k >= 0)
				free((*matrix)[k--]);
			free(*matrix);
			close(fd);
			perror("Error reading file");
			exit(EXIT_FAILURE);
		}
		ft_strncpy((*matrix)[k], line, mlx->columns);
		(*matrix)[k][mlx->columns] = '\0';
		free(line);
		k++;
	}
}

void	allocate_for_lines(t_mlx *mlx, char ***matrix)
{
	int	k;

	k = 0;
	while (k < mlx->lines)
	{
		(*matrix)[k] = (char *)malloc(sizeof(char) * (mlx->columns + 1));
		if (!(*matrix)[k])
		{
			while (k > 0)
				free((*matrix)[--k]);
			free(*matrix);
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		k++;
	}
	(*matrix)[k] = NULL;
}

void	allocate_and_passing(t_mlx *mlx, char *str, char ***matrix)
{
	int	fd;

	*matrix = (char **)malloc(sizeof(char *) * (mlx->lines + 1));
	if (!*matrix)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	allocate_for_lines(mlx, matrix);
	fd = open(str, O_RDONLY);
	fd_verification(mlx, matrix, fd);
	passing(mlx, matrix, fd);
	close(fd);
}

void	verificate_file_length(int fd, t_mlx *mlx)
{
	char	*file;

	mlx->lines = 0;
	mlx->verify = -1337;
	file = get_next_line(fd);
	while (file != NULL)
	{
		mlx->columns = column_number(file, fd, mlx);
		if (mlx->verify == -1337)
			mlx->verify = mlx->columns;
		if (mlx->verify != mlx->columns)
		{
			free(file);
			close(fd);
			end(2, mlx);
		}
		free(file);
		file = get_next_line(fd);
		mlx->lines++;
	}
	free(file);
	close(fd);
}

void	verificate_map_and_init(char *str, int fd)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	verificate_extension(str, mlx);
	verificate_file_length(fd, mlx);
	allocate_and_passing(mlx, str, &mlx->matrix);
	allocate_and_passing(mlx, str, &mlx->copy);
	wall_verification_and_other(mlx);
	finish_that_stupid_verifications(mlx);
	init_game(mlx);
	end(3, mlx);
	exit(0);
}
