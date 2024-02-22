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

/*
** Free map struct & player struct when texture or image failed to load
*/
void	free_malloc_error(t_map *map)
{
	free(map->player);
	free_struct_map(map);
	error_check(MALLOC_ERROR, NULL);
}
