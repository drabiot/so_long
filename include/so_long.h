/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:59 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/02 19:17:40 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx42/include/MLX42_Int.h"

# ifndef SPRITE_PIXEL
#  define SPRITE_PIXEL 64
# endif //SPRITE_PIXEL

enum	e_error
{
	FEW_ARGV_ERROR,
	MANY_ARGV_ERROR,
	EXTENSION_ERROR,
	FEW_PLAYER_ERROR,
	MANY_PLAYER_ERROR,
	FEW_EXIT_ERROR,
	MANY_EXIT_ERROR,
	FEW_COLLECTIBLE_ERROR,
	WALLS_ERROR,
	SIZE_ERROR,
	PATH_EXIT_ERROR,
	PATH_COLLECTIBLE_ERROR,
} ;


#endif //SO_LONG_H
