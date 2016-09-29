# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 16:22:08 by ple-lez           #+#    #+#              #
#    Updated: 2016/07/06 12:15:04 by ple-lez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LFT = libft/libft.a
LIBS = $(LFT) -L./ -lmlx
HPATH = -I./
SRC = main.c ft_draw.c ft_init.c ft_key.c
CC = gcc -g -Wall -Werror -Wextra
C_MLX = $(MLX) -framework OpenGL -framework AppKit
AR = ar - cvq libft.a
RM = rm -rf
SRCDIR = $(addprefix ./src/, $(SRC))
OBJDIR = obj
OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))

$(NAME):
	@make -C libft
	@$(CC) -c $(SRCDIR)
	@mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
	@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(C_MLX) $(HPATH)

all: $(NAME)

clean:
	@$(RM) $(OBJDIR)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean
	@make re -C libft
	@make all
	@make clean

.PHONY: all clean fclean
