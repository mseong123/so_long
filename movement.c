/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:17:26 by melee             #+#    #+#             */
/*   Updated: 2023/06/14 08:50:12 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_string(t_data *data)
{
	char	*str;

	str = ft_itoa(data->count_move);
	put_image(data, data->wall, 2, 0);
	ft_putstr_fd("Moves: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 100, 25, 0xffffff, str);
	free(str);
}

void	up(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;
	if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != 'E')
	{
		if (x == data->enemy->x && y - 1 == data->enemy->y)
		{
			ft_putstr_fd("YOU LOSE!\n", 1);
			exit_game(data);
		}
		put_image(data, data->floor, x, y);
		data->player->y -= 1;
		put_image(data, data->floor, x, y - 1);
		put_image(data, data->player->up, x, y - 1);
		data->count_move += 1;
		put_string(data);
		if (data->map[y - 1][x] == 'C')
			move_collect(data, x, y - 1);
	}
	else if (data->map[y - 1][x] == 'E' && data->exit_status)
		exit_game(data);
}

void	down(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;
	if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != 'E')
	{	
		if (x == data->enemy->x && y + 1 == data->enemy->y)
		{
			ft_putstr_fd("YOU LOSE!\n", 1);
			exit_game(data);
		}
		put_image(data, data->floor, x, y);
		data->player->y += 1;
		put_image(data, data->floor, x, y + 1);
		put_image(data, data->player->down, x, y + 1);
		data->count_move += 1;
		put_string(data);
		if (data->map[y + 1][x] == 'C')
			move_collect(data, x, y + 1);
	}
	else if (data->map[y + 1][x] == 'E' && data->exit_status)
		exit_game(data);
}

void	left(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;
	if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != 'E')
	{
		if (x - 1 == data->enemy->x && y == data->enemy->y)
		{
			ft_putstr_fd("YOU LOSE!\n", 1);
			exit_game(data);
		}
		put_image(data, data->floor, x, y);
		data->player->x -= 1;
		put_image(data, data->floor, x - 1, y);
		put_image(data, data->player->left, x - 1, y);
		data->count_move += 1;
		put_string(data);
		if (data->map[y][x - 1] == 'C')
			move_collect(data, x - 1, y);
	}
	else if (data->map[y][x - 1] == 'E' && data->exit_status)
		exit_game(data);
}

void	right(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != 'E')
	{
		if (x + 1 == data->enemy->x && y == data->enemy->y)
		{
			ft_putstr_fd("YOU LOSE!\n", 1);
			exit_game(data);
		}
		put_image(data, data->floor, x, y);
		data->player->x += 1;
		put_image(data, data->floor, x + 1, y);
		put_image(data, data->player->right, x + 1, y);
		data->count_move += 1;
		put_string(data);
		if (data->map[y][x + 1] == 'C')
			move_collect(data, x + 1, y);
	}
	else if (data->map[y][x + 1] == 'E' && data->exit_status)
		exit_game(data);
}
