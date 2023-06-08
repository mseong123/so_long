/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:34:32 by melee             #+#    #+#             */
/*   Updated: 2023/06/08 12:37:12 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	handle_key(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
		printf("%p\n", data->mlx_win);
		free_data(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	handle_destroy(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}
