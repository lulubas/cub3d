# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damendez <damendez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 10:23:30 by agheredi          #+#    #+#              #
#    Updated: 2024/04/18 16:44:48 by damendez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings/flags
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# Source filenames
FILES = ft_printf pf_arg_c pf_arg_d pf_arg_p pf_arg_s pf_arg_u pf_arg_x pf_read_text pf_search_arg \
		get_next_line get_next_line_utils \
		ft_strlen ft_nbrlen ft_putnbr ft_putchar ft_putstr ft_strncmp

# Generating source objects and depedency files
SRC = $(FILES:%=$(SRC_DIR)/%.c)
OBJ = $(FILES:%=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Includes file
INCLUDES = -I$(INC_DIR)

# Target executable name
TARGET = libft.a

# Check for required librqiries and generate default target
all: $(TARGET)

# Compile .cpp files into .o object files. Check that obj/ is created.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

#Creates the obj directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create target sstatic library from object files
$(TARGET): $(OBJ)
	$(AR) $@ $(OBJ)

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
.PHONY: all clean fclean re