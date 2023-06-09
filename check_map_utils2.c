/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:34:49 by melee             #+#    #+#             */
/*   Updated: 2023/06/09 16:49:33 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' 
				&& data->map[i][j] != 'C' && data->map[i][j] != 'E' 
				&& data->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_exit(t_data *data)
{
	int	exit;
	int	i;
	int	j;

	exit = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' && exit == 0)
				exit++;
			else if (data->map[i][j] == 'E' && exit == 1)
				return (0);
			j++;
		}
		i++;
	}
	if (exit == 0)
		return (0);
	else
		return (1);
}

int	check_start(t_data *data)
{
	int	start;
	int	i;
	int	j;

	start = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && start == 0)
				start++;
			else if (data->map[i][j] == 'P' && start == 1)
				return (0);
			j++;
		}
		i++;
	}
	if (start == 0)
		return (0);
	else
		return (1);
}

int	check_collectible(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			if (data->map[i][j++] == 'C')
				return (1);
		i++;
	}
	return (0);
}

