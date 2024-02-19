/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:10:54 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/03 18:27:47 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"
#include "../include/libft.h"

/*
** Free the given list type map
*/
void	free_struct_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < map->height)
	{
		free(map->display_map[i]);
		i++;
	}
	free(map->display_map);
	free (map);
}

/*
** Free the given matrix & its arrays
*/
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/*
** Check for the given map's extension
*/
void	extension_check(char *map, char *arg)
{
	int	len;

	len = ft_strlen(map);
	if (len < 4)
	{
		error_check(EXTENSION_ERROR, arg);
		exit(1);
	}
	else if (len >= 4 && ft_strncmp(&map[len - 4], ".ber", 4))
	{
		error_check(EXTENSION_ERROR, arg);
		exit(1);
	}
}

/*
** Check the numbers of the given character are in the given map
*/
int	check_nb(t_map *map, char c)
{
	int	nb;
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	nb = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->display_map[i][j] == c)
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

/*
** Create error messages
*/
void	error_check(int error, char *arg)
{
	char	*error_message[14];

	error_message[FEW_ARGV_ERROR] = "(Too few arguments)";
	error_message[MANY_ARGV_ERROR] = "(Too many arguments)";
	error_message[EXTENSION_ERROR] = "(Map doesn't end with .ber )";
	error_message[FEW_PLAYER_ERROR] = "(Player doesn't exist)";
	error_message[MANY_PLAYER_ERROR] = "(Too many Player)";
	error_message[FEW_EXIT_ERROR] = "(Exit doesn't exist)";
	error_message[MANY_EXIT_ERROR] = "(Too many Exit)";
	error_message[FEW_COLLECTIBLE_ERROR] = "(There are no Collectibles)";
	error_message[WALLS_ERROR] = "(The map isn't surrounded by walls)";
	error_message[SIZE_ERROR] = "(The map isn't rectangular)";
	error_message[PATH_EXIT_ERROR] = "(No path leading to the Exit)";
	error_message[PATH_COLLECTIBLE_ERROR] = "(No path leading to at least 1 \
Colletible)";
	error_message[NO_MAP_ERROR] = "(Can't load the map)";
	error_message[MAP_ERROR] = "(The map's composed characters \
isn't correct)";
	ft_printf("Error\n%s\n", error_message[error]);
	if (arg)
		free(arg);
	exit (1);
}
