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

void	error_check(int error)
{
	char	*error_message[12];

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
	error_message[PATH_COLLECTIBLE_ERROR] = "(No pat leading to at lest 1 Colletible)";
	ft_printf("Error\n%s\n", error_message[error]);
	exit (1);
}