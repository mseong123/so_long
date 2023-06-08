/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:41:04 by melee             #+#    #+#             */
/*   Updated: 2023/06/08 19:00:51 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void init_null(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
}




int	render(t_data *data)
{
	//printf("%p\n", data->mlx_ptr);
	char	*path = "./sprites/fence.xpm";
	char	*path1 = "./sprites/cut.xpm";
	void	*img;
	void	*img1;
	int	img_width;
	int	img_height;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width, &img_height);
	img1 = mlx_xpm_file_to_image(data->mlx_ptr, path1, &img_width, &img_height);
	printf("%d\n",img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, 50, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img1, 50, 50);

	return(0);

}


void init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "So Long");
	if (!data->mlx_win)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	mlx_hook(data->mlx_win, KEYPRESS, 0, handle_key, data);
	mlx_hook(data->mlx_win, DESTROY, 0, handle_destroy, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
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
