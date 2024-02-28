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
	MALLOC_ERROR,
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
	mlx_texture_t	*banner[6];
	mlx_texture_t	*number[11];
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
	mlx_image_t	*banner[6];
	mlx_image_t	*number[11];
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
	int				dead;
	t_player		*player;
	mlx_t			*mlx;
	t_textures		*tx;
	t_images		*img;
}					t_map;

/* ********************************************************** */
/*                                                            */
/*                        create_map.c                        */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                 map_init()                 */
/*       Create the list that contains        */
/*         the information of the map         */
/* ****************************************** */
void	map_init(t_map **map, char *arg);

/* ****************************************** */
/*              map_node_init()               */
/*      Assign values to the given list       */
/* ****************************************** */
t_map	*map_node_init(t_map **map, char *full_map, int width, char *arg);

/* ********************************************************** */
/*                                                            */
/*         check_map.c & check_path.c & check_wall.c          */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                check_map()                 */
/*    Check the validity of the given map     */
/* ****************************************** */
void	check_map(t_map **map, char *arg);

/* ****************************************** */
/*              ft_flood_fill()               */
/*    Flood fill the map starting from the    */
/*       given coordinate of the player       */
/* ****************************************** */
void	ft_flood_fill(t_map **map, int x, int y);

/* ****************************************** */
/*                check_path()                */
/*     Check the validity of the map and      */
/*       ensure that the exit & all the       */
/*        collectibles are accessible         */
/* ****************************************** */
void	check_path(t_map **map, t_player **player, char *arg);

/* ****************************************** */
/*               check_walls()                */
/*      Check the validity of the map by      */
/*   verifying if it is properly surrounded   */
/*                  by walls                  */
/* ****************************************** */
void	check_walls(t_map **map, char *arg);

/* ********************************************************** */
/*                                                            */
/*                       error_check.c                        */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*               error_check()                */
/*           Create error messages            */
/* ****************************************** */
void	error_check(int error, char *arg);

/* ****************************************** */
/*             extension_check()              */
/*    Check for the given map's extension     */
/* ****************************************** */
void	extension_check(char *map, char *arg);

/* ****************************************** */
/*                 check_nb()                 */
/*  Check the numbers of the given character  */
/*            are in the given map            */
/* ****************************************** */
int		check_nb(t_map *map, char c);

/* ****************************************** */
/*               free_matrix()                */
/*     Free the given matrix & its arrays     */
/* ****************************************** */
void	free_matrix(char **matrix);

/* ****************************************** */
/*             free_struct_map()              */
/*        Free the given list type map        */
/* ****************************************** */
void	free_struct_map(t_map *map);

/* ****************************************** */
/*            free_malloc_error()             */
/*    Free map struct & player struct when    */
/*      texture or image failed to load       */
/* ****************************************** */
void	free_malloc_error(t_map *map);

void	error_texture(t_map *map);
void	destroy_walls_tx(t_map *map);

void	destroy_numbers_tx(t_map *map);
void	destroy_texture(t_map *map);
/* ********************************************************** */
/*                                                            */
/*                        ft_random.c                         */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                 ft_srand()                 */
/*         Initialize the given seed          */
/* ****************************************** */
void	ft_srand(unsigned int seed);

/* ****************************************** */
/*                 ft_rand()                  */
/*   Take two numbers and provide a random    */
/*            number between them             */
/* ****************************************** */
int		ft_rand(int a, int b);

/* ********************************************************** */
/*                                                            */
/*                         display.c                          */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*              display_floor()               */
/*      Display randomly the map's floor      */
/* ****************************************** */
void	display_floor(t_map *map, int i, int j);

/* ****************************************** */
/*               display_map()                */
/*   Display everything related to the map    */
/* ****************************************** */
void	display_map(t_map *map, t_player *player);

/* ********************************************************** */
/*                                                            */
/*                         copy_map.c                         */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                 copy_map()                 */
/*     Duplicate the given map (char **)      */
/*               and return it                */
/* ****************************************** */
char	**copy_map(t_map *map);

/* ********************************************************** */
/*                                                            */
/*          game_init.c & images_init.c animation.c           */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                game_init()                 */
/*            Iniatizate the game             */
/* ****************************************** */
void	game_init(t_map *map, t_player *player);

/* ****************************************** */
/*                 init_png()                 */
/*         Create textures and images         */
/* ****************************************** */
void	init_png(t_map *map);

/* ****************************************** */
/*                animation()                 */
/* Create the animation for the collectibles, */
/*          the player & the enemies          */
/* ****************************************** */
void	animation(t_map *map);

/* ********************************************************** */
/*                                                            */
/*               player_init.c & key_press.c                  */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*               player_init()                */
/*         Initialize the player list         */
/* ****************************************** */
void	player_init(t_map **map, t_player **player, char *arg);

/* ****************************************** */
/*              display_player()              */
/*             Display the player             */
/* ****************************************** */
void	display_player(t_map *map, t_player *player);

/* ****************************************** */
/*                key_press()                 */
/*         Check the pressed key and          */
/*          take action accordingly           */
/* ****************************************** */
void	key_press(mlx_key_data_t keydata, t_map *map);

/* ********************************************************** */
/*                                                            */
/*                         ai_enemy.c                         */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                 ai_enemy()                 */
/*       Flood fill the map and assign        */
/*     a value to each of the cells based     */
/*       on the given starting position       */
/* ****************************************** */
void	ai_enemy(char **map, char **travel_map, int x, int y);

/* ****************************************** */
/*            check_flood_enemy()             */
/*            Check the flood fill            */
/* ****************************************** */
void	check_flood_enemy(char **map, char **travel_map, int x, int y);

/* ********************************************************** */
/*                                                            */
/*                      calculate_cost.c                      */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*            cost_move_enemy_x()             */
/*     Look for the smallest value around     */
/*            the given coordinates           */
/*           on the horizontal axis           */
/* ****************************************** */
int		cost_move_enemy_x(char **map, int x, int y);

/* ****************************************** */
/*            cost_move_enemy_y()             */
/*     Look for the smallest value around     */
/*            the given coordinates           */
/*           on the verticalal axis           */
/* ****************************************** */
int		cost_move_enemy_y(char **map, int x, int y);

/* ****************************************** */
/*               move_enemy_x()               */
/*     Check if the enemy should move up      */
/*   or down based on the given coordinates   */
/* ****************************************** */
int		move_enemy_x(char **map, int x, int y);

/* ****************************************** */
/*               move_enemy_y()               */
/*    Check if the enemy should move right    */
/*   or down based on the given coordinates   */
/* ****************************************** */
int		move_enemy_y(char **map, int x, int y);

/* ********************************************************** */
/*                                                            */
/*                       counter_init.c                       */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*             texture_numbers()              */
/*    Generate the textures of the numbers    */
/* ****************************************** */
void	texture_numbers(t_map *map);

/* ****************************************** */
/*              image_numbers()               */
/*        Convert the textures of the         */
/*            numbers into images             */
/* ****************************************** */
void	image_numbers(t_map *map);

/* ****************************************** */
/*             display_counter()              */
/*      Place the numbers in the correct      */
/*     positions within the game & place      */
/*       the banner in the right place        */
/* ****************************************** */
void	display_counter(t_map *map);

/* ********************************************************** */
/*                                                            */
/*                          score.c                           */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*             hide_all_number()              */
/*        hide all the numbers of one         */
/*              instance (tile)               */
/* ****************************************** */
void	hide_all_number(t_map *map, int instance);

/* ****************************************** */
/*              reveal_number()               */
/*      Reveal the given number into the      */
/*           given instance (tile)            */
/* ****************************************** */
void	reveal_number(t_map *map, int instance, int value);

/* ****************************************** */
/*               update_score()               */
/*    Update the move score of the player     */
/* ****************************************** */
void	update_score(t_map *map, int move);

/* ****************************************** */
/*             track_coll_unity()             */
/*  Look at and modify the appearance of the  */
/*      score banner based on the score       */
/* ****************************************** */
int		track_coll_unity(t_map *map, int i, int coll);

/* ****************************************** */
/*             track_coll_base()              */
/*     Look at and split the given score      */
/* ****************************************** */
int		track_coll_base(t_map *map, int i, int coll);

/* ********************************************************** */
/*                                                            */
/*                       track_score.c                        */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*        display_score_collectible()         */
/*       Display the collectible score        */
/* ****************************************** */
void	display_score_collectible(t_map *map);

/* ****************************************** */
/*           display_numbers_coll()           */
/*         Display the right numbers          */
/*          at the start of the game          */
/* ****************************************** */
void	display_numbers_coll(t_map *map);

/* ********************************************************** */
/*                                                            */
/*            defeat.c & enemy_init.c & move_enemy.c          */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                  defeat()                  */
/*     Perform all the necessary actions      */
/*          after the player's death          */
/* ****************************************** */
void	defeat(t_map *map);

/* ****************************************** */
/*                enemy_init()                */
/*      Initialize the number of enemies      */
/*           based on the given map           */
/* ****************************************** */
void	enemy_init(t_map *map);

/* ****************************************** */
/*            pathfinding_enemy()             */
/*     Search for where the enemy should      */
/*              move on the map               */
/* ****************************************** */
void	pathfinding_enemy(t_map *map);

/* ****************************************** */
/*                move_enemy()                */
/*              Move the enemies              */
/* ****************************************** */
void	move_enemy(t_map *map, char **cpy_map);

/* ********************************************************** */
/*                                                            */
/*                          sound.c                           */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                play_sound()                */
/*            Play the given sound            */
/* ****************************************** */
void	play_sound(char *path);

/* ****************************************** */
/*               kill_sounds()                */
/*             Kill all the sound             */
/* ****************************************** */
void	kill_sounds(void);

/* ****************************************** */
/*             play_collectible()             */
/*        Play randomly the sound when        */
/*         player grab a collectible          */
/* ****************************************** */
void	play_collectible(void);

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
