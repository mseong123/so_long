/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:41:04 by melee             #+#    #+#             */
/*   Updated: 2023/06/12 18:41:19 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
		up(data);
	else if (keycode == 0 || keycode == 123)
		left(data);
	else if (keycode == 2 || keycode == 124)
		right(data);	
	else if (keycode == 1 || keycode == 125)
		down(data);	
	else if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		free_map(data);
		//free(data->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);	
}

int	handle_destroy(t_data *data)
{
	(void)data;
	free_map(data);
	//free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}


void	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("so_long");
		exit(EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, \
	get_column(data) * PIX_W, get_row(data) * PIX_H, \
    "so_long");
	if (!data->mlx_win)
	{
		perror("so_long");
		exit(EXIT_FAILURE);
	}
	initialise_image(data);
	put_image_to_map(data);

	
	
		
}


int	main(int argc, char **argv)
{
	t_data		data;
	t_player	player;
	
	if (argc == 2)
	{
		check_map(&data, argv);
		data.player = &player;
		init(&data);
		mlx_hook(data.mlx_win, KEYPRESS, 0, handle_key, &data);
		mlx_hook(data.mlx_win, DESTROY, 0, handle_destroy, &data);
		mlx_loop(data.mlx_ptr);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error! Enter correct no. of parameters\n", 2);
		return (EXIT_FAILURE);
	}
}
