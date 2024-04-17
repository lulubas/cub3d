# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 22:10:10 by lbastien          #+#    #+#              #
#    Updated: 2022/11/08 17:06:48 by lbastien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

SRC_B =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		

NAME =		libft.a

CC =		gcc
CFLAG =		-Wall -Wextra -Werror

AR =		ar rcs
RM =		rm -f

OBJ =		$(SRC:%.c=%.o)
OBJ_B = 	$(SRC_B:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus:		$(OBJ) $(OBJ_B)
	$(AR) $(NAME) $(OBJ) $(OBJ_B)

%.o: 		%.c
	$(CC) $(CFLAG) -I./ -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: 	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
