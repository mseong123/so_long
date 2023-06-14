/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:00:37 by melee             #+#    #+#             */
/*   Updated: 2023/06/14 09:01:09 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
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
*/

static int	check_adj_exit(t_data *data, int y, int x)
{
	if (data->map[y + 1][x] == 'E' || data->map[y - 1][x] == 'E'
		|| data->map[y][x - 1] == 'E' || data->map[y][x + 1] == 'E')
		return (1);
	return (0);
}

static	int	recursive(t_data *data, char **map_check, int y, int x)
{
	map_check[y][x] = 'Y';
	if (check_adj_exit(data, y, x))
		return (1);
	if ((data->map[y + 1][x] == 'C' || data->map[y + 1][x] == '0')
			&& map_check[y + 1][x] != 'Y')
		if (recursive(data, map_check, y + 1, x))
			return (1);
	if ((data->map[y - 1][x] == 'C' || data->map[y - 1][x] == '0')
			&& map_check[y - 1][x] != 'Y')
		if (recursive(data, map_check, y - 1, x))
			return (1);
	if ((data->map[y][x + 1] == 'C' || data->map[y][x + 1] == '0')
			&& map_check[y][x + 1] != 'Y')
		if (recursive(data, map_check, y, x + 1))
			return (1);
	if ((data->map[y][x - 1] == 'C' || data->map[y][x - 1] == '0')
			&& map_check[y][x - 1] != 'Y')
		if (recursive(data, map_check, y, x - 1))
			return (1);
	return (0);
}

static void	get_p(t_data *data, int curr[2])
{
	curr[0] = 0;
	while (data->map[curr[0]])
	{	
		curr[1] = 0;
		while (data->map[curr[0]][curr[1]])
		{
			if (data->map[curr[0]][curr[1]] == 'P')
				break ;
			curr[1]++;
		}
		if (data->map[curr[0]][curr[1]] == 'P')
			break ;
		curr[0]++;
	}
}

int	check_path(t_data *data)
{
	int		i;
	char	**map_cell_checker;
	int		pos_p[2];
	int		res;

	i = 0;
	map_cell_checker = ft_calloc(get_row(data) + 1, sizeof(char *));
	while (i < get_row(data))
		map_cell_checker[i++] = ft_calloc(get_column(data) + 1, sizeof(char));
	get_p(data, pos_p);
	res = recursive(data, map_cell_checker, pos_p[0], pos_p[1]);
	i = 0;
	while (i < get_row(data) + 1)
		free(map_cell_checker[i++]);
	free(map_cell_checker);
	return (res);
}
