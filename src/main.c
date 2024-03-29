/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:27:33 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/10 17:39:53 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

/*
** Create path leading to maps folder if needed
*/
static char	*create_arg(char *argv)
{
	char	*arg;

	if (ft_strncmp(argv, "maps/", 5) != 0)
		arg = ft_strjoin(ft_strdup("maps/"), ft_strdup(argv));
	else
		arg = ft_strdup(argv);
	if (!arg)
		error_check(NO_MAP_ERROR, arg);
	return (arg);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;
	char		*arg;	

	map = NULL;
	arg = NULL;
	if (argc < 2)
		error_check(FEW_ARGV_ERROR, arg);
	else if (argc > 2)
		error_check(MANY_ARGV_ERROR, arg);
	else
	{
		arg = create_arg(argv[1]);
		extension_check(argv[1], arg);
		map_init(&map, arg);
		player_init(&map, &player, arg);
		check_path(&map, &player, arg);
		free(arg);
		game_init(map, player);
		free(map->img);
		destroy_numbers_tx(map);
		destroy_texture(map);
		mlx_terminate(map->mlx);
		free_struct_map(map);
	}
}
