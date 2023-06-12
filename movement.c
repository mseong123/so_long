/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:17:26 by melee             #+#    #+#             */
/*   Updated: 2023/06/12 18:42:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;
	if (y > 0 && data->map[y - 1][x] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, x * PIX_W, y * PIX_H); 
	data->player->y -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player->up, x * PIX_W, (y - 1) * PIX_H);
	}
	
}

void	down(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;

	if (y < get_row(data) && data->map[y + 1][x] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, x * PIX_W, y * PIX_H); 
	data->player->y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player->down, x * PIX_W, (y + 1) * PIX_H);
	}
}

void	left(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;

	if (x > 0 && data->map[y][x - 1] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, x * PIX_W, y * PIX_H); 
	data->player->x -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player->left, (x - 1) * PIX_W, y * PIX_H);
	}
}

void	right(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;

	if (y < get_column(data) && data->map[y][x + 1] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, x * PIX_W, y * PIX_H); 
	data->player->x+= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player->right, (x + 1) * PIX_W, y * PIX_H);
	}
}


