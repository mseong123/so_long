/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:47:55 by melee             #+#    #+#             */
/*   Updated: 2023/06/09 16:47:02 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1000
# define HEIGHT 500
# define KEYPRESS 2
# define DESTROY 17

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
}		t_data;

void	free_map(t_data *data);
void	check_map(t_data *data, char **argv);
int		check_rectangular(t_data *data);
int		check_char(t_data *data);
int		check_min_row_column(t_data *data);
int		check_wall(t_data *data);
int		check_exit(t_data *data);
int		check_start(t_data *data);
int		check_collectible(t_data *data);


#endif
