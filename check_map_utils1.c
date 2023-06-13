/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:35 by melee             #+#    #+#             */
/*   Updated: 2023/06/13 13:54:56 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_data *data)
{
	int i;
	int j;
	int first_column;
	
	i = 0;
	first_column = 0;
	while (data->map[0] && data->map[0][first_column])
		first_column++;
	while (data->map[i])
	{
		j = 0;
		while(data->map[i][j])
			j++;
		if (j != first_column)
		   return (0);	
		i++;
	}
   	if (i == j)
		return (0);	
	return (1);
}

int	get_row(t_data *data)
{
	int row;

	row = 0;
	while (data->map[row])
		row++;
	return (row);
}

int	get_column(t_data *data)
{
	int column;

	column = 0;
	while (data->map[0] && data->map[0][column])
		column++;
	return (column);
}

int	check_min_row_column(t_data *data)
{
	int	row;
	int column;

	row = get_row(data);
	column = get_column(data);
	if (row < 5 || column < 5)
		return (0);
	else
		return (1);
}

int	check_wall(t_data *data)
{
	int	row;
	int	column;
	int	i;

	row = get_row(data);
	column = get_column(data);
	i = 0;
	while (data->map[0][i])
		if (data->map[0][i++] != '1')
			return (0);
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][column - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (data->map[row - 1][i])
		if (data->map[row - 1][i++] != '1')
			return (0);
	return (1);
}

