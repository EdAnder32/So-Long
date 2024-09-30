/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:44:26 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/13 23:44:55 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../utils/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>

typedef struct s_struct
{
	int		columns;
	int		lines;
	int		verify;
	int		y_start;
	int		x_start;
	char	new_chr;
	char	old_chr;
	char	**copy;
	char	**matrix;
	void	*connection;
	void	*window;
	void	*image;
	void	*s_image;
	void	*choice;
	void	*player;
	void	*c_p;
	void	*i7;
	void	*car;
	char	*car_rigth;
	char	*car_up;
	char	*car_left;
	char	*car_down;
	void	*c;
	char	*c_img;
	void	*w;
	char	*w_img;
	void	*f;
	char	*f_img;
	void	*g;
	char	*g_img;
	int		player_x;
	int		player_y;
	int		x;
	int		y;
	int		d;
	int		width;
	int		heigth;
	int		exit_x;
	int		exit_y;
	int		img_w;
	int		img_h;
	int		car_x;
	int		car_y;
	int		playerr;
	int		rest_of_colet;
	int		output;
	int		direction_y;
	int		direction_x;
	int		moviments;
	int		times;
	char	*e_img;
	void	*e;
	char	ch;
}		t_mlx;

/*FILE_NAME: so_logic_2.c*/
void	extend(t_mlx *mlx, void *car);
void	end_over(t_mlx *mlx);
int		end_game(char c, int colet);
void	end_message(t_mlx *mlx);
void	fd_verification(t_mlx *mlx, char ***matrix, int fd);

/*FILE_NAME: so_logic.c*/
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_rigth(t_mlx *mlx);
void	move_left(t_mlx *mlx);
int		position(int key, t_mlx *mlx);

/*FILE_NAME: so_graphics_extras_2.c*/
void	set_images_and_dimentions(t_mlx *mlx);
void	ultimate_end_mlx(t_mlx *mlx);
void	set_initial_value(t_mlx *mlx);
int		strchr_on_matrix(char **matrix, char c);
void	see_matrix(char **matrix, t_mlx *mlx);

/*FILE_NAME: so_graphics_extras.c*/
int		down_window(t_mlx *mlx);
int		ked_pressed(int key, t_mlx *mlx);
void	load_pointers_for_img(t_mlx *mlx, void *tmp);
void	second_end_mlx(t_mlx *mlx);
int		shut_window(t_mlx *mlx);

/*FILE_NAME: so_graphics_3.c*/
void	im_tired(t_mlx *mlx, int k, int x, void	*tmp);
void	draw_things_on_screen(t_mlx *mlx, void	*tmp);
void	mounting_map(t_mlx *mlx);
void	first_position_for_car(t_mlx *mlx);
void	game_screen(t_mlx *mlx);

/*FILE_NAME: so_graphics_2.c*/
int		ked_pressed(int key, t_mlx *mlx);
void	selected_car_img_two(int car_code, t_mlx *mlx);
void	selected_car_img(int car_code, t_mlx *mlx);
int		get_car(int key, int x, int y, t_mlx *mlx);
void	second_screen(t_mlx *mlx);

/*FILE_NAME: so_graphics.c*/
void	first_end_mlx(t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		ke_pressed(int key, t_mlx *mlx);
int		first_screen(int key, t_mlx *mlx);
void	init_game(t_mlx *mlx);

/*FILE_NAME: so_finally_end.c*/
void	free_matrix(char **matrix);
void	end(int n, t_mlx *mlx);

/*FILE_NAME: so_verifications_3.c*/
char	*ft_strncpy(char *dest, char *src, int n);
void	now_other(t_mlx *mlx);
void	wall_verification_and_other(t_mlx *mlx);
void	verificate_extension(char *str, t_mlx *mlx);
int		column_number(char *str, int fd, t_mlx *mlx);

/*FILE_NAME: so_verifications_2.c*/
void	flood_fill(int x, int y, t_mlx *mlx);
void	finding_start_point(char **matrix, t_mlx *mlx, char c);
void	sending_to_flood_fill(t_mlx *mlx);
void	finish_that_stupid_verifications(t_mlx *mlx);

/*FILE_NAME: so_verifications.c*/
void	allocate_and_passing(t_mlx *mlx, char *str, char ***matrix);
void	verificate_file_length(int fd, t_mlx *mlx);
void	verificate_map_and_init(char *str, int fd);
#endif
