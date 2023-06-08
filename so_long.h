/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:47:55 by melee             #+#    #+#             */
/*   Updated: 2023/06/08 18:43:22 by melee            ###   ########.fr       */
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

typedef struct	s_data {
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;

void	free_data(t_data *data);
int		handle_key(int keysym, t_data *data);
int		handle_destroy(t_data *data);

#endif
