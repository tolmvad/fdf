#SETUP
NAME		=	fdf
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
FRAMEWORK	=	-Lmlx -lm -lmlx -framework OpenGL -framework AppKit -O3

#FILES AND PATH
HEADERS_SRC	=	fdf.h color.h error.h keys.h menu.h settings.h
HEADS		=	$(addprefix includes/, $(HEADERS_SRC))
HEADERS		=	$(HEADS) gnl/get_next_line.h

SRC_SRCS	=	fdf.c grids.c pars.c memory.c error.c do_hooks.c \
				hooks_handler.c axes.c draw.c pixel_put.c point.c color.c \
				utils.c
SRC_DIR		=	sources/
SRC			=	$(addprefix $(SRC_DIR), $(SRC_SRCS))
OBJ			=	$(SRC:.c=.o)

FUNC_SRCS	=	ft_atoi.c ft_isdigit.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o: %.c $(HEADERS) Makefile
				@${CC} ${FLAGS} -Imlx -c $< -o $@

$(NAME):		$(OBJ) $(OBJ_F)
				@$(CC) $(OBJ) $(OBJ_F) $(FRAMEWORK) -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			@make -C mlx/ all
				$(NAME)

clean:
				@$(RM) $(OBJ)
				@$(RM) $(OBJ_F)
				@make -C mlx/ clean
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
