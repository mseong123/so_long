/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:37:21 by melee             #+#    #+#             */
/*   Updated: 2023/06/13 13:03:20 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_collect(t_data *data, int x, int y)
{
	int i;
	int j;

	i = 0;	
	data->map[y][x] = '0';
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				break;
			j++;
		}
		if (data->map[i][j] == 'E')
			break;
		i++;
	}
	if (!check_collectible(data))
	{
		put_image(data, data->exit1, j, i);
		data->exit_status = 1;
	}
}
