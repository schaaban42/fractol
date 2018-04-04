# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 09:41:23 by schaaban          #+#    #+#              #
#    Updated: 2018/04/04 13:43:22 by schaaban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol

CC			=		gcc
FLAGS		=		-Wall -Werror -Wextra

INC_DIR		=		./includes
SRCS_DIR	=		./srcs
OBJS_DIR	=		./objs

LFT_DIR		=		./libft
LFT_I_DIR	=		$(LFT_DIR)/includes
LFT_NAME	=		ft

MLIB_DIR	=		./minilibx_macos
MLIB_I_DIR	=		$(MLIB_DIR)
MLIB_NAME	=		mlx

CC_INC		=		-I$(INC_DIR) -I$(LFT_I_DIR) -I$(MLIB_I_DIR)
CC_LINK		=		-L$(LFT_DIR) -l$(LFT_NAME) -L$(MLIB_DIR) -l$(MLIB_NAME)
CC_MLIB		=		-framework OpenGL -framework AppKit

SRCS		=		$(addprefix $(SRCS_DIR)/, 	\
					main.c						\
					key_pressed.c				\
					exit.c						\
					graphics.c					\
					fractal.c					\
					tools.c						\
					mouse.c						\
					init.c						\
					init_fractals.c				\
					ui.c						)
OBJS		=		$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[1;34m
COLOR_GREEN	=	\033[1;32m
COLOR_WHITE	=	\033[0m

all: $(NAME)

$(NAME): dir_creation $(OBJS)
	@echo "$(COLOR_BLUE)FRACT'OL - $(COLOR_GREEN)Compiling exe...$(COLOR_WHITE)"
	@$(MAKE) -C $(LFT_DIR)
	@$(MAKE) -C $(MLIB_DIR)
	@$(CC) $(FLAGS) $(OBJS) $(CC_INC) $(CC_LINK) $(CC_MLIB) -o $(NAME)
	@echo "$(COLOR_BLUE)FRACT'OL - $(COLOR_GREEN)Done !$(COLOR_WHITE)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC_DIR)/$(NAME).h $(INC_DIR)/mlx_keys.h
	@$(CC) $(FLAGS) $(CC_INC) -o $@ -c $<

dir_creation:
	@echo "$(COLOR_BLUE)FRACT'OL - $(COLOR_GREEN)Objs creation...$(COLOR_WHITE)"
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(COLOR_BLUE)FRACT'OL - $(COLOR_RED)Cleaning objs...$(COLOR_WHITE)"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LFT_DIR) clean
	@$(MAKE) -C $(MLIB_DIR) clean

fclean: clean
	@echo "$(COLOR_BLUE)FRACT'OL - $(COLOR_RED)Cleaning libft...$(COLOR_WHITE)"
	@rm -rf $(NAME)
	@$(MAKE) -C $(LFT_DIR) fclean
	@$(MAKE) -C $(MLIB_DIR) clean

re: fclean all

.PHONY: all re clean fclean dir_creation
