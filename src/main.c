/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:27:33 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/03 18:39:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;	

	map = NULL;
	if (argc < 2)
		error_check(FEW_ARGV_ERROR);
	else if (argc > 2)
		error_check(MANY_ARGV_ERROR);
	else
	{
		extension_check(argv[1]);
		map_init(&map, argv[1]);
		display(&map);
	}
}
