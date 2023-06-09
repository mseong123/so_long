/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:35 by melee             #+#    #+#             */
/*   Updated: 2023/06/09 14:23:46 by melee            ###   ########.fr       */
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
	while (data->map[0][first_column++])
		;
	while (data->map[i])
	{
		j = 0;
		while(data->map[i][j++])
			;
		if (j != first_column)
		   return (0);	
		i++;
	}
	return (1);
}

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
