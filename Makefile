# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 17:07:24 by lbastien          #+#    #+#              #
#    Updated: 2024/05/24 01:04:55 by lbastien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings/flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
MLX_FLAGS =	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
MLX_DIR = lib/mlx
LIB_DIR = lib/libft

# Source filenames
FILES = cub3d init free checker parser \
		print list_utils map_utils check_map check_textures_and_colors \
		render parser_map raycast input utils \
		mlx_conf draw draw_utils moves free_utils

# Generating source objects and depedency files
SRC = $(FILES:%=$(SRC_DIR)/%.c)
OBJ = $(FILES:%=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Required local libraries
LIBFT = $(LIB_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Includes file
INCLUDES = -I$(INC_DIR) -I$(LIB_DIR)/inc -I$(MLX_DIR)

# Target executable name
TARGET = cub3d

# Check for required librairies and generate default target
all: $(LIBFT) $(MLX) $(TARGET)

# Buld the librairies if
$(LIBFT) $(MLX):
	$(MAKE) -C $(@D)

# Run target executable
run: all
	@./$(TARGET)

# Compile .cpp files into .o object files. Check that obj/ is created.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS)  $(INCLUDES) -MMD -MP -c $< -o $@

#Creates the obj directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link object files into the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(TARGET)

# Clean up objects and dependency files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	
# Also clean up the target executable
fclean: clean
	rm -f $(TARGET) $(LIBFT)

# Clean up and recompile
re: fclean all

# Include dependencies files in the Make process
-include $(DEP)

# List of phony targets
.PHONY: $(LIBFT) $(MLX) all clean fclean re run
