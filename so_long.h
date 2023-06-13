/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:47:55 by melee             #+#    #+#             */
/*   Updated: 2023/06/13 16:46:31 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PIX_W 50
# define PIX_H 50
# define KEYPRESS 2
# define DESTROY 17

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_player
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	int		x;
	int		y;
}	t_player;

typedef struct	s_enemy
{
	void	**img;
	int		x;
	int		y;
	int		frame;
	int		img_index;
	int		sign;
}	t_enemy;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_player	*player;
	t_enemy		*enemy;
	void		*floor;
	void		*exit;
	void		*exit1;
	void		*wall;
	void		*collect;
	char		**map;
	int			count_move;
	int			exit_status;
}		t_data;

void	free_map(t_data *data);
void	exit_game(t_data *data);
void	check_map(t_data *data, char **argv);
int		check_rectangular(t_data *data);
int		check_char(t_data *data);
int		check_min_row_column(t_data *data);
int		check_wall(t_data *data);
int		check_exit(t_data *data);
int		check_start(t_data *data);
int		get_row(t_data *data);
int		get_column(t_data *data);
int		check_collectible(t_data *data);
int		check_path(t_data *data);
void	init_image(t_data *data);
void	init_enemy_image(t_data *data);
void	put_image_to_map(t_data *data);
void	put_image(t_data *data, void *image, int j, int i);
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
void	put_string(t_data *data);
void	move_collect(t_data *data, int x, int y);
int		animation(t_data *data);
void	get_enemy_pos(t_data *data);


#endif
