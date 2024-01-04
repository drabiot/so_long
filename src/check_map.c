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

static void	check_player(t_map **map)
{
	int		nb_player;
	int		i;
	int		j;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	nb_player = 0;
	i = 0;
	while (current->display_map[i])
	{
		j = 0;
		while (current->display_map[i][j])
		{
			if (current->display_map[i][j] == 'P')
				nb_player++;
			j++;
		}
		i++;
	}
	if (nb_player < 1)
		error_check(FEW_PLAYER_ERROR);
	else if (nb_player > 1)
		error_check(MANY_PLAYER_ERROR);
}

static void	check_exit(t_map **map)
{
	int		nb_exit;
	int		i;
	int		j;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	nb_exit = 0;
	i = 0;
	while (current->display_map[i])
	{
		j = 0;
		while (current->display_map[i][j])
		{
			if (current->display_map[i][j] == 'E')
				nb_exit++;
			j++;
		}
		i++;
	}
	if (nb_exit < 1)
		error_check(FEW_EXIT_ERROR);
	else if (nb_exit > 1)
		error_check(MANY_EXIT_ERROR);
}

static void	check_collectible(t_map **map)
{
	int		nb_collectible;
	int		i;
	int		j;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	nb_collectible = 0;
	i = 0;
	while (current->display_map[i])
	{
		j = 0;
		while (current->display_map[i][j])
		{
			if (current->display_map[i][j] == 'C')
				nb_collectible++;
			j++;
		}
		i++;
	}
	if (nb_collectible < 1)
		error_check(FEW_COLLECTIBLE_ERROR);
}

static void	check_characters(t_map **map)
{
	int		i;
	int		j;
	t_map	*current;
	char	character;

	if (!map || !*map)
		return ;
	current = *map;
	i = 0;
	while (current->display_map[i])
	{
		j = 0;
		while (current->display_map[i][j])
		{
			character = current->display_map[i][j];
			if (!(character == '0' || character == '1' || character == 'C'
					|| character == 'E' || character == 'P'))
				error_check(MAP_ERROR);
			j++;
		}
		i++;
	}
}

void	check_map(t_map **map)
{
	check_player(map);
	check_exit(map);
	check_collectible(map);
	check_walls(map);
	check_characters(map);
}
