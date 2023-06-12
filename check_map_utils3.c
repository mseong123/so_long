/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:00:37 by melee             #+#    #+#             */
/*   Updated: 2023/06/12 12:58:31 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_adj_exit(t_data *data, int y, int x)
{
	if (data->map[y + 1][x] == 'E' || data->map[y - 1][x] == 'E' || data->map[y][x -1] == 'E'
			|| data->map[y][x + 1] == 'E')
		return (1);
	return (0);
}

int	recursive(t_data *data, char **map_check, int y, int x)
{
	if (check_adj_exit(data, y, x))
		return (1);
	if ((data->map[y + 1][x] == 'C' || data->map[y + 1][x] == '0') && map_check[y + 1][x] != 'Y')
	{
		map_check[y + 1][x] = 'Y';
		if(recursive(data, map_check, y + 1, x))
			return (1);
	}
	
	if ((data->map[y - 1][x] == 'C' || data->map[y - 1][x] == '0') && map_check[y - 1][x] != 'Y')
	{	
		map_check[y - 1][x] = 'Y';
		if (recursive(data, map_check, y - 1, x))
			return (1);
	}	
	if ((data->map[y][x + 1] == 'C' || data->map[y][x + 1] == '0') && map_check[y][x + 1] != 'Y')
	{	
		map_check[y][x + 1] = 'Y';
		if (recursive(data, map_check, y, x + 1))
		{
			printf("here\n");
			return (1);
		}
	}
	if ((data->map[y][x - 1] == 'C' || data->map[y][x - 1] == '0') && map_check[y][x - 1] != 'Y')
	{	
		map_check[y][x - 1] = 'Y';
		if (recursive(data, map_check, y, x - 1))
			return (1);
	}	
	return (0);
}

static void	get_P(t_data *data, int curr[2])
{
	curr[0] = 0;
	while (data->map[curr[0]])
	{	
		curr[1] = 0;
		while (data->map[curr[0]][curr[1]])
		{
			if (data->map[curr[0]][curr[1]] == 'P')
				break;
			curr[1]++;
		}
		if (data->map[curr[0]][curr[1]] == 'P')
			break;
		curr[0]++;
	}
}

void	print_check(t_data *data, char **map_check)
{
	int i = 0;
	int row = get_row(data);
	int	j = 0;
	int column = get_column(data);

	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (map_check[i][j] == '\0')
				printf("0");
			else 
				printf("%c",map_check[i][j]);
			j++;
		}
		printf("\n");
	i++;	
	}
}

int	check_path(t_data *data)
{
	int i;
	char **map_check;
	int	curr[2];
	int res;

	i = 0;
	res = 0;
	map_check = ft_calloc(get_row(data) + 1, sizeof(char *));
	while (i < get_row(data))
	{
		map_check[i] = ft_calloc(get_column(data) + 1, sizeof(char));
		i++;
	}
	
	get_P(data, curr);
	printf("%d\n", curr[0]);
	printf("%d\n", curr[1]);
	res = recursive(data, map_check, curr[0], curr[1]);
	print_check(data,map_check);	
	printf("result %d\n", res);
	return (0);
	
}
