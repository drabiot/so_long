/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:21:34 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/11 16:21:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_init(t_map **map, t_player **player)
{
	int	i;
	int	j;

	*player = malloc(sizeof(t_player));
	if (!*player)
		exit(1);
	i = 0;
	(*player)->pos_x = -1;
	(*player)->pos_y = -1;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			if ((*map)->display_map[i][j] == 'P')
			{
				(*player)->pos_x = j;
				(*player)->pos_y = i;
			}
			j++;
		}
		i++;
	}
}


