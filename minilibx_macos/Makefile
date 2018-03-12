#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[1;34m
COLOR_GREEN	=	\033[1;32m
COLOR_WHITE	=	\033[0m

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "$(COLOR_BLUE)MLX - $(COLOR_GREEN)Compiling mlx...$(COLOR_WHITE)"
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "$(COLOR_BLUE)MLX - $(COLOR_GREEN)Done !$(COLOR_WHITE)"

clean:
	@echo "$(COLOR_BLUE)MLX - $(COLOR_RED)Cleaning mlx...$(COLOR_WHITE)"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all

.SILENT: $(OBJ)
