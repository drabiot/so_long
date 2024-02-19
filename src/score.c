/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:12:05 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/16 14:12:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hide_all_number(t_map *map, int instance)
{
	map->img->number[0]->instances[instance].enabled = 0;
	map->img->number[1]->instances[instance].enabled = 0;
	map->img->number[2]->instances[instance].enabled = 0;
	map->img->number[3]->instances[instance].enabled = 0;
	map->img->number[4]->instances[instance].enabled = 0;
	map->img->number[5]->instances[instance].enabled = 0;
	map->img->number[6]->instances[instance].enabled = 0;
	map->img->number[7]->instances[instance].enabled = 0;
	map->img->number[8]->instances[instance].enabled = 0;
	map->img->number[9]->instances[instance].enabled = 0;
}

void	reveal_number(t_map *map, int instance, int value)
{
	map->img->number[value]->instances[instance].enabled = 1;
}

void	update_score(t_map *map, int move)
{
	hide_all_number(map, 0);
	reveal_number(map, 0, (move / 100));
	move %= 100;
	hide_all_number(map, 1);
	reveal_number(map, 1, (move / 10));
	move %= 10;
	hide_all_number(map, 2);
	reveal_number(map, 2, move);
}

int	track_coll_unity(t_map *map, int i, int coll)
{
	if (coll >= 0)
	{
		reveal_number(map, i, coll);
		i++;
	}
	if (i >= 6)
		map->img->banner[5]->instances[i - 6].enabled = 1;
	return (i);
}

int	track_coll_base(t_map *map, int i, int coll)
{
	while (coll >= 0)
	{
		if (coll / 100 > 0)
		{
			reveal_number(map, i, coll / 100);
			coll %= 100;
			i++;
			reveal_number(map, i, coll / 10);
			coll %= 10;
			i++;
		}
		else if (coll / 10 > 0)
		{
			reveal_number(map, i, coll / 10);
			coll %= 10;
			i++;
		}
		else if (coll >= 0)
		{
			i = track_coll_unity(map, i, coll);
			coll -= 10;
		}
	}
	return (i);
}
