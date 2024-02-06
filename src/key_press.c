/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:22:38 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/05 18:23:02 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"

static void	enter_trapdoor(t_map *map)
{
	if (map->display_map[map->player->pos_y][map->player->pos_x] == 'E'
		&& map->img->exit[1]->instances[0].enabled == 1)
	{
		ft_printf("You eat all the Cheese!");
		mlx_close_window(map->mlx);
	}
}

static void	player_grab_collectible(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = map->player->pos_x * SPRITE_PIXEL;
	y = map->player->pos_y * SPRITE_PIXEL;
	if (map->display_map[map->player->pos_y][map->player->pos_x] == 'C')
	{
		map->player->coll++;
		map->display_map[map->player->pos_y][map->player->pos_x] = 'c';
		while ((size_t)i < map->img->collectible[0]->count
			&& !(map->img->collectible[0]->instances[i].y == y
				&& map->img->collectible[0]->instances[i].x == x))
			i++;
		map->img->collectible[0]->instances[i].enabled = 0;
		map->img->collectible[1]->instances[i].enabled = 0;
	}
	if (map->player->coll == map->tot_coll)
	{
		map->img->exit[0]->instances[0].enabled = 0;
		map->img->exit[1]->instances[0].enabled = 1;
	}
}

static void	move_player(t_map *map, int new_x, int new_y)
{
	static int	nb_move = 0;
	int			new_x_player;
	int			new_y_player;

	new_x_player = map->player->pos_x + new_x / SPRITE_PIXEL;
	new_y_player = map->player->pos_y + new_y / SPRITE_PIXEL;
	if (!(map->display_map[new_y_player][new_x_player] == '1'))
	{
		map->img->player->instances[0].x += new_x;
		map->img->player->instances[0].y += new_y;
		nb_move++;
		map->player->pos_x = new_x_player;
		map->player->pos_y = new_y_player;
		ft_printf("Number of moves : %d\n", nb_move);
	}
	player_grab_collectible(map);
}

void	key_press(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_player(map, 0, -SPRITE_PIXEL);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_player(map, 0, SPRITE_PIXEL);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_player(map, -SPRITE_PIXEL, 0);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_player(map, SPRITE_PIXEL, 0);
	enter_trapdoor(map);
}
