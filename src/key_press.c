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

static void	move_player(t_map *map, int new_x, int new_y)
{
	map->img->player->instances[0].x += new_x;
	map->img->player->instances[0].y += new_y;
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
}
