/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:27:33 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/04 20:18:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;
	char		*arg;	

	map = NULL;
	if (argc < 2)
		error_check(FEW_ARGV_ERROR);
	else if (argc > 2)
		error_check(MANY_ARGV_ERROR);
	else
	{
		arg = ft_strjoin("maps/", argv[1]);
		extension_check(argv[1]);
		map_init(&map, arg);
		player_init(&map, &player);
		check_path(&map, &player);
		display(&map, &player);
	}
}
