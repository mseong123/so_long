/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:41:04 by melee             #+#    #+#             */
/*   Updated: 2023/06/08 12:35:23 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void init_null(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
}

void init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx_ptr, LENGTH, WIDTH, "So Long");
	if (!data->mlx_win)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	mlx_hook(data->mlx_win, KEYPRESS, 0, handle_key, data);
	mlx_hook(data->mlx_win, DESTROY, 0, handle_destroy, data);
	mlx_loop(data->mlx_ptr);
}

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	
	init(data);


	return (EXIT_SUCCESS);
}
