/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:52 by melee             #+#    #+#             */
/*   Updated: 2023/06/13 16:08:13 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_data *data)
{
	int	width;
	int	height;

	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/floor.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/door.xpm", &width, &height);
	data->exit1 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/door_open.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/wall.xpm", &width, &height);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/coin.xpm", &width, &height);
	data->player->right = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/right.xpm", &width, &height);
	data->player->left = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/left.xpm", &width, &height);
	data->player->up = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/up.xpm", &width, &height);
	data->player->down = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/down.xpm", &width, &height);
}

void	init_enemy_image(t_data *data)
{
	int i;
	int	width;
	int	height;

	i = 0;
	data->enemy->img = malloc(6 * sizeof(void *));
	while (i < 6)
		data->enemy->img[i++] = NULL;
	data->enemy->img[0] = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/slime1.xpm", &width, &height);
	data->enemy->img[1] = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/slime2.xpm", &width, &height);
	data->enemy->img[2] = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/slime3.xpm", &width, &height);
	data->enemy->img[3] = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/slime4.xpm", &width, &height);
	data->enemy->img[4] = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/slime5.xpm", &width, &height);
}

void	put_image(t_data *data, void *image, int j, int i)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image,\
	j * PIX_W, i * PIX_H);
}

void	put_image_to_map2(t_data *data, int j, int i)
{
	if (data->map[i][j] == 'C')
	{
		put_image(data, data->floor, j, i);
		put_image(data, data->collect, j, i);
	}
	else if (data->map[i][j] == 'E')
		put_image(data, data->exit, j, i);
	else if (data->map[i][j] == 'P')
	{
		put_image(data, data->floor, j, i);
		put_image(data, data->player->right, j, i);
		data->player->x = j;
		data->player->y = i;
	}
}

void	put_image_to_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i] && data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_image(data, data->wall, j, i);
			else if (data->map[i][j] == '0')
				put_image(data, data->floor, j, i);
					j++;
			put_image_to_map2(data, j, i);
		}
		i++;
	}
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 25, 0xffffff, "Moves: ");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 100, 25, 0xffffff, "0");
}
