/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:52 by melee             #+#    #+#             */
/*   Updated: 2023/06/12 18:11:53 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise_image(t_data *data)
{
	int	width;
	int	height;

	data->space = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/grass.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/door.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/fence.xpm", &width, &height);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/slime.xpm", &width, &height);
	data->player->right = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/right.xpm", &width, &height);
	data->player->left = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/left.xpm", &width, &height);
	data->player->up = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/up.xpm", &width, &height);
	data->player->down = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/down.xpm", &width, &height);
}

void	put_image_to_map(t_data *data)
{

	int	i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i] && data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, j * PIX_W, i * PIX_H);
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->wall, j * PIX_W, i * PIX_H);
			}
			
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, j * PIX_W, i * PIX_H);
			
			else if (data->map[i][j] == 'C')
			{
				
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, j * PIX_W, i * PIX_H);
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->collect, j * PIX_W, i * PIX_H);
			}	
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->exit, j * PIX_W, i * PIX_H);
			else if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->space, j * PIX_W, i * PIX_H);
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player->right, j * PIX_W, i * PIX_H);
				data->player->x = j;
				data->player->y = i;
			}
			
			j++;
		}
		i++;
	}


}
