# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 17:25:51 by tchartie          #+#    #+#              #
#    Updated: 2024/01/02 19:26:32 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=		so_long

#========= COMPILATOR =========#

CC			=		clang

#=========== FLAGS ============#

CFLAGS		=		-Wall -Wextra -Werror
GFLAGS		=		$(CFLAGS) -g
MLX_FLAGS	=		-ldl -lX11 -lglfw -lm -lz -lbsd -lXext

#=========== COLOR ============#

BASE_COLOR 	=		\033[0;39m
GRAY 		=		\033[0;90m
RED 		=		\033[0;91m
GREEN 		=		\033[0;92m
YELLOW 		=		\033[0;93m
BLUE 		=		\033[0;94m
MAGENTA		=		\033[0;95m
CYAN 		=		\033[0;96m
WHITE		=		\033[0;97m

#========== SOURCES ===========#

INCLUDE_DIR	=		include
INC_MLX_DIR	=		mlx42/include
INCLUDE		=		$(INCLUDE_DIR)/so_long.h

LIBFT_DIR	=		libft
PRINTF_DIR	=		ft_printf
MLX_DIR		=		mlx42

SRCS_DIR	=		src/
OBJS_DIR	=		obj/

SRCS		=		main.c \
					error_check.c \
					create_map.c \
					get_next_line.c \
					get_next_line_utils.c \
					check_map.c \
					check_walls.c \
					check_path.c \
					display.c 

OBJS		=		$(SRCS:.c=.o)

SRCS_F		=		$(addprefix $(SRCS_DIR),$(SRCS))
OBJS_F		=		$(addprefix $(OBJS_DIR),$(OBJS))

#========= EXECUTABLE =========#

all :				$(NAME)

makemlx :
					@git clone https://github.com/codam-coding-college/MLX42.git mlx42
					@cmake -B mlx42/src mlx42
					@make -C $(MLX_DIR)/src -j4 --no-print-directory
					@mv mlx42/include/MLX42/MLX42_Int.h mlx42/include

makelibft :
					@make -C $(LIBFT_DIR) all --no-print-directory
makeprintf :
					@make -C $(PRINTF_DIR) all --no-print-directory

$(NAME) :			makemlx $(OBJS_F) | makelibft makeprintf
					@$(CC) $(OBJS_F) $(MLX_FLAGS) -o $(NAME) -Llibft -lft -Lft_printf -l:ft_printf.a -Lmlx42/src -lmlx42 -I$(INCLUDE_DIR) -I$(INC_MLX_DIR)
					@echo "$(GREEN)Pipex successfully compiled! $(BASE_COLOR)"

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(INCLUDE)
					@mkdir -p $(OBJS_DIR)
					@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
					@$(CC) $(GFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean :
					@rm -rf $(OBJS_DIR)
					@make -C $(LIBFT_DIR) clean --no-print-directory
					@make -C $(PRINTF_DIR) clean --no-print-directory
					@echo "$(BLUE)Pipex objects files cleanned! $(BASE_COLOR)"

fclean :
					@rm -rf $(OBJS_DIR)
					@rm -rf $(MLX_DIR)
					@echo "$(BLUE)Pipex objects files cleanned! $(BASE_COLOR)"
					@rm -rf $(NAME)
					@echo "$(CYAN)Pipex executable file cleanned! $(BASE_COLOR)"
					@make -C $(LIBFT_DIR) fclean --no-print-directory
					@make -C $(PRINTF_DIR) fclean --no-print-directory
					
re :				fclean all

.PHONY :			all makemlx makelibft makeprintf clean fclean re
