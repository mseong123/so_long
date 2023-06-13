/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:41:31 by melee             #+#    #+#             */
/*   Updated: 2023/06/13 18:34:00 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_enemy_pos(t_data *data)
{
	int	i;
	int	j;

	i = get_row(data) / 2;
	while (data->map[i])
	{
		j = get_column(data) / 2;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' && data->map[i][j + 1] == '0')
			{
				data->enemy->x = j;
				data->enemy->y = i;
				break ;
			}
			j++;
		}
		if (data->map[i][j] == '0' && data->map[i][j + 1] == '0')
			break ;
		i++;
	}
	data->enemy->sign = 1;
}

static void	move_enemy(t_data *data)
{
	if (data->enemy->sign == 1)
	{
		if (data->map[data->enemy->y][data->enemy->x + 1] == '0')
			data->enemy->x++;
		else
		{
			data->enemy->x--;
			data->enemy->sign = 0;
		}	
	}
	else
	{
		if (data->map[data->enemy->y][data->enemy->x - 1] == '0')
			data->enemy->x--;
		else
		{
			data->enemy->x++;
			data->enemy->sign = 1;
		}	
	}	
}

int	animation(t_data *data)
{
	data->enemy->frame++;
	if (data->enemy->frame == 2500)
	{
		if (data->enemy->frame == 2500)
			data->enemy->frame = 0;
		if (data->enemy->x == data->player->x && data->enemy->y == data->player->y)
			exit_game(data);
		if (data->enemy->img_index == 0 && data->enemy->sign == 1
			&& data->map[data->enemy->y][data->enemy->x - 1] == '0')
			put_image(data, data->floor, data->enemy->x - 1, data->enemy->y);
		if (data->enemy->img_index == 0 && data->enemy->sign == 0
			&& data->map[data->enemy->y][data->enemy->x + 1] == '0')
			put_image(data, data->floor, data->enemy->x + 1, data->enemy->y);
		put_image(data, data->floor, data->enemy->x, data->enemy->y);
		put_image(data, data->enemy->img[data->enemy->img_index], \
		data->enemy->x, data->enemy->y);
		data->enemy->img_index++;
		if (data->enemy->img_index == 5)
		{
			move_enemy(data);
			data->enemy->img_index = 0;
		}
	}
	return (0);
}
