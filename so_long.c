/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:41:04 by melee             #+#    #+#             */
/*   Updated: 2023/06/09 13:45:03 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		check_map(&data, argv);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error! Enter correct no. of parameters\n", 2);
		return (EXIT_FAILURE);
	}
}
