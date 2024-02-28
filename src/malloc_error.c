/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 02:12:12 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/22 02:12:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_walls_tx(t_map *map)
{
	int	i;

	i = 0;
	if (map->tx->floor[0])
		mlx_delete_texture(map->tx->floor[0]);
	if (map->tx->floor[1])
		mlx_delete_texture(map->tx->floor[1]);
	if (map->tx->floor[2])
		mlx_delete_texture(map->tx->floor[2]);
	while (i < 4)
	{
		if (map->tx->wall[i])
			mlx_delete_texture(map->tx->wall[i]);
		if (map->tx->corner[i])
			mlx_delete_texture(map->tx->corner[i]);
		i++;
	}
	if (map->tx->obs[0])
		mlx_delete_texture(map->tx->obs[0]);
}

void	destroy_numbers_tx(t_map *map)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (map->tx->number[i])
			mlx_delete_texture(map->tx->number[i]);
		i++;
	}
}

void	destroy_texture(t_map *map)
{
	int	i;

	i = 0;
	destroy_walls_tx(map);
	while (i < 2)
	{
		if (map->tx->player[i])
			mlx_delete_texture(map->tx->player[i]);
		if (map->tx->collec[i])
			mlx_delete_texture(map->tx->collec[i]);
		if (map->tx->exit[i])
			mlx_delete_texture(map->tx->exit[i]);
		if (map->tx->enemy[i])
			mlx_delete_texture(map->tx->enemy[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (map->tx->banner[i])
			mlx_delete_texture(map->tx->banner[i]);
		i++;
	}
	free(map->tx);
}

void	error_texture(t_map *map)
{
	if (!map)
		return ;
	destroy_texture(map);
	free_malloc_error(map);
}

/*
** Free map struct & player struct when texture or image failed to load
*/
void	free_malloc_error(t_map *map)
{
	if (map)
	{
		if (map->player)
			free(map->player);
		map->player = NULL;
		free_struct_map(map);
		error_check(MALLOC_ERROR, NULL);
	}
}
