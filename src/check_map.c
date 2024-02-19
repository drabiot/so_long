/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:53:57 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/04 18:08:11 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
** Check the number of player on the given map
*/
static void	check_player(t_map **map, char *arg)
{
	int		nb_player;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	nb_player = check_nb(current, 'P');
	if (nb_player != 1)
	{
		free_struct_map(current);
		if (nb_player < 1)
			error_check(FEW_PLAYER_ERROR, arg);
		else if (nb_player > 1)
			error_check(MANY_PLAYER_ERROR, arg);
	}
}

/*
** Check the number of exit on the given map
*/
static void	check_exit(t_map **map, char *arg)
{
	int		nb_exit;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	nb_exit = check_nb(current, 'E');
	if (nb_exit != 1)
	{
		free_struct_map(current);
		if (nb_exit < 1)
			error_check(FEW_EXIT_ERROR, arg);
		else if (nb_exit > 1)
			error_check(MANY_EXIT_ERROR, arg);
	}
}

/*
** Check the number of collectibles on the given map
*/
static void	check_collectible(t_map **map, char *arg)
{
	int		nb_collectible;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	nb_collectible = check_nb(current, 'C');
	if (nb_collectible < 1)
	{
		free_struct_map(current);
		error_check(FEW_COLLECTIBLE_ERROR, arg);
	}
	current->tot_coll = nb_collectible;
}

/*
** Check the written characters on the given map
*/
static void	check_characters(t_map **map, char *arg)
{
	int		i;
	int		j;
	t_map	*current;
	char	character;

	if (!map || !*map)
		return ;
	current = *map;
	i = 0;
	while (i < current->height)
	{
		j = 0;
		while (j < current->width)
		{
			character = current->display_map[i][j];
			if (!(character == '0' || character == '1' || character == 'C'
					|| character == 'E' || character == 'P'))
			{
				free_struct_map(current);
				error_check(MAP_ERROR, arg);
			}
			j++;
		}
		i++;
	}
}

/*
** Check the validity of the given map
*/
void	check_map(t_map **map, char *arg)
{
	check_player(map, arg);
	check_exit(map, arg);
	check_collectible(map, arg);
	check_walls(map, arg);
	check_characters(map, arg);
}
