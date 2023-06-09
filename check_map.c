/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:42:29 by melee             #+#    #+#             */
/*   Updated: 2023/06/09 13:55:15 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_suffix(char **argv)
{
	char	*suffix;

	suffix = ft_strrchr(argv[1], '.');
	if (!suffix || ft_strcmp(suffix, ".ber"))
	{
		ft_putstr_fd("Error! Enter a file with correct extension .ber\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void check_map_conditions(t_data *data)
{
	if (!check_rectangular(data))
	{
		ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
		free_map(data);
		exit(EXIT_FAILURE);
	}
	if (!check_char(data))
	{
		ft_putstr_fd("Error\nWrong character used for map.", 2);
		ft_putstr_fd("Use only 0,1,C,E,P.\n", 2);
		free_map(data);
		exit(EXIT_FAILURE);
	}
}

static void parse_map(int fd, t_data *data)
{
	char	*line;
	char	*file;
	char	*temp;

	line = get_next_line(fd);
	file = ft_calloc(1, sizeof(char));
	while (line && file)
	{
		temp = file;
		file = ft_strjoin(file, line);
		free(line);
		free(temp);
		line = get_next_line(fd);	
	}
	free(line);
	data->map = ft_split(file, '\n');
	free(file);
}

void	check_map(t_data *data, char **argv)
{
	int		fd;
	char	*path;

	check_suffix(argv);
	path = ft_strjoin("./maps/", argv[1]);
	fd = open(path, O_RDONLY);
	free(path);
   	if (fd == -1)
	{
		perror("so_long");
		exit(EXIT_FAILURE);
	}
	parse_map(fd, data);
	check_map_conditions(data);
}
	