# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 17:07:24 by lbastien          #+#    #+#              #
#    Updated: 2024/04/16 14:52:28 by lbastien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS =	-Lmlx -lmlx -framework OpenGL -framework AppKit

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
MLX_DIR = mlx

# Source filenames
FILES = cub3d

# Generating source objects and depedency files
SRC = $(FILES:%=$(SRC_DIR)/%.c)
OBJ = $(FILES:%=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Target executable name
TARGET = cub3d

# Default target
all: $(TARGET)

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
	
# Also clean up the target executable
fclean: clean
	rm $(TARGET)

# Clean up and recompile
re: fclean all

# Include dependencies files in the Make process
-include $(DEP)

# List of phony targets
.PHONY: all run clean fclean re
