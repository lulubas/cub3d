# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 17:07:24 by lbastien          #+#    #+#              #
#    Updated: 2024/04/16 17:30:11 by lbastien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings/flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS =	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
MLX_DIR = mlx
LIB_DIR = libft

# Source filenames
FILES = cub3d

# Generating source objects and depedency files
SRC = $(FILES:%=$(SRC_DIR)/%.c)
OBJ = $(FILES:%=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Required local libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Includes file
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Target executable name
TARGET = cub3d

# Check for required librqiries and generate default target
all: $(LIBFT) $(MLX) $(TARGET)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build the MiniLibX library
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Run target executable
run: all
	@./$(TARGET)

# Compile .cpp files into .o object files. Check that obj/ is created.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

#Creates the obj directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link object files into the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Clean up objects and dependency files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	
# Also clean up the target executable
fclean: clean
	rm $(TARGET) $(LIBFT) $(MLX)

# Clean up and recompile
re: fclean all

# Include dependencies files in the Make process
-include $(DEP)

# List of phony targets
.PHONY: all run clean fclean re
