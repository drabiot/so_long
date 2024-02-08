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
#include "../include/ft_printf.h"

static void	destroy_texture(t_map *map)
{
	mlx_delete_texture(map->tx->floor[0]);
	mlx_delete_texture(map->tx->floor[1]);
	mlx_delete_texture(map->tx->floor[2]);
	mlx_delete_texture(map->tx->player);
	mlx_delete_texture(map->tx->wall[0]);
	mlx_delete_texture(map->tx->wall[1]);
	mlx_delete_texture(map->tx->wall[2]);
	mlx_delete_texture(map->tx->wall[3]);
	mlx_delete_texture(map->tx->corner[0]);
	mlx_delete_texture(map->tx->corner[1]);
	mlx_delete_texture(map->tx->corner[2]);
	mlx_delete_texture(map->tx->corner[3]);
	mlx_delete_texture(map->tx->obstacle[0]);
	mlx_delete_texture(map->tx->collectible[0]);
	mlx_delete_texture(map->tx->collectible[1]);
	mlx_delete_texture(map->tx->exit[0]);
	mlx_delete_texture(map->tx->exit[1]);
}

static void	destroy_image(t_map *map)
{
	mlx_delete_image(map->mlx, map->img->floor[0]);
	mlx_delete_image(map->mlx, map->img->floor[1]);
	mlx_delete_image(map->mlx, map->img->floor[2]);
	mlx_delete_image(map->mlx, map->img->player);
	mlx_delete_image(map->mlx, map->img->wall[0]);
	mlx_delete_image(map->mlx, map->img->wall[1]);
	mlx_delete_image(map->mlx, map->img->wall[2]);
	mlx_delete_image(map->mlx, map->img->wall[3]);
	mlx_delete_image(map->mlx, map->img->corner[0]);
	mlx_delete_image(map->mlx, map->img->corner[1]);
	mlx_delete_image(map->mlx, map->img->corner[2]);
	mlx_delete_image(map->mlx, map->img->corner[3]);
	mlx_delete_image(map->mlx, map->img->obstacle[0]);
	mlx_delete_image(map->mlx, map->img->collectible[0]);
	mlx_delete_image(map->mlx, map->img->collectible[1]);
	mlx_delete_image(map->mlx, map->img->exit[0]);
	mlx_delete_image(map->mlx, map->img->exit[1]);
}

static char	*create_arg(char *argv)
{
	char	*arg;

	if (ft_strncmp(argv, "maps/", 5) != 0)
		arg = ft_strjoin(ft_strdup("maps/"), ft_strdup(argv));
	else
		arg = ft_strdup(argv);
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
		player_init(&map, &player);
		check_path(&map, &player, arg);
		free(arg);
		game_init(map, player);
		destroy_image(map);
		destroy_texture(map);
		mlx_terminate(map->mlx);
		free_struct_map(map);
		free(player);
	}
}
