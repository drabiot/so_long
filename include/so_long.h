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
# include <stdlib.h>

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
	NO_MAP_ERROR,
	MAP_ERROR,
} ;

typedef struct s_textures
{
	mlx_texture_t	*floor[3];
	mlx_texture_t	*player[2];
	mlx_texture_t	*wall[4];
	mlx_texture_t	*corner[4];
	mlx_texture_t	*obs[1];
	mlx_texture_t	*collec[2];
	mlx_texture_t	*exit[2];
	mlx_texture_t	*enemy[2];
}			t_textures;

typedef struct s_images
{
	mlx_image_t	*floor[3];
	mlx_image_t	*player[2];
	mlx_image_t	*wall[4];
	mlx_image_t	*corner[4];
	mlx_image_t	*obs[1];
	mlx_image_t	*collec[2];
	mlx_image_t	*exit[2];
	mlx_image_t	*enemy[2];
}			t_images;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	coll;
}		t_player;

typedef struct s_map
{
	int				height;
	int				width;
	char			**display_map;
	int				pos_x_exit;
	int				pos_y_exit;
	int				tot_coll;
	t_player		*player;
	mlx_t			*mlx;
	t_textures		*tx;
	t_images		*img;
}					t_map;

void	error_check(int error, char *arg);
void	extension_check(char *map, char *arg);
void	map_init(t_map **map, char *arg);
t_map	*map_node_init(t_map **map, char *full_map, int width, char *arg);
void	check_map(t_map **map, char *arg);
void	check_walls(t_map **map, char *arg);
int		check_nb(t_map *map, char c);
void	player_init(t_map **map, t_player **player);
void	ft_flood_fill(t_map **map, int x, int y);
void	check_path(t_map **map, t_player **player, char *arg);
void	free_struct_map(t_map *map);
void	free_matrix(char **matrix);

void	display_map(t_map *map, t_player *player);

void	init_png(t_map *map);
void	game_init(t_map *map, t_player *player);

void	ft_srand(unsigned int seed);
int		ft_rand(int a, int b);

void	display(t_map **map, t_player **player);
void	hook(t_map *map);

void	key_press(mlx_key_data_t keydata, t_map *map);
void	display_floor(t_map *map, int i, int j);
void	display_player(t_map *map, t_player *player);

void	enemy_init(t_map *map);
char	**copy_map(t_map *map);
void	ai_enemy(char **map, char **travel_map, int x, int y);
void	pathfinding_enemy(t_map *map);
void	check_flood_enemy(char **map, char **travel_map, int x, int y);

int	cost_move_enemy_x(char **map, int x, int y);
int	cost_move_enemy_y(char **map, int x, int y);
int	move_enemy_x(char **map, int x, int y);
int	move_enemy_y(char **map, int x, int y);

void	move_enemy(t_map *map, char **cpy_map);
void	animation(t_map *map);

/* ********************************************************** */
/*                                                            */
/*                       get_next_line                        */
/*                                                            */
/* ********************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFER_SIZE

/* ****************************************** */
/*               get_next_line                */
/*     Take a file descriptor and return      */
/*                   a line                   */
/* ****************************************** */
char	*get_next_line(int fd);

/* ****************************************** */
/*                 read_buff                  */
/*     Take a file descriptor and read it     */
/* ****************************************** */
char	*read_buff(int fd, char *stash);

/* ****************************************** */
/*                add_to_line                 */
/*       Take the line finished by a \n       */
/*                & return it                 */
/* ****************************************** */
char	*add_to_line(char *stash);

/* ****************************************** */
/*                clean_stash                 */
/*     Remove the line add into the stash     */
/* ****************************************** */
char	*clean_stash(char *stash);

/* ********************************************************** */
/*                                                            */
/*                    get_next_line_utils                     */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                  new_line                  */
/*   See if there a newline into the stash    */
/* ****************************************** */
int		new_line(char *str);

/* ****************************************** */
/*               ft_strjoin_gnl               */
/*    Take two string and concatenate them    */
/* ****************************************** */
char	*ft_strjoin_gnl(char *s1, char *s2);

/* ****************************************** */
/*                 ft_strccpy                 */
/*         Take a string and copy it          */
/* ****************************************** */
char	*ft_strccpy(char *dst, const char *src, int check_nl);

#endif //SO_LONG_H
