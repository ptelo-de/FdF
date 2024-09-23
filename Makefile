.SILENT:

NAME			=	fdf

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -gdwarf-4 #-fsanitize=thread

RM				=	rm -rf

INC_DIR			=	includes/

SRC_DIR			=	sources/

OBJ_DIR			=	objs/


MLX_PATH		=	$(addprefix $(LIBS_DIR), minilibx-linux/)

LINKS			=	-lm -lXext -lX11 -L$(MLX_PATH) -lmlx -L$(LFT_PATH) -lft

SRC				=	$(addprefix $(SRC_DIR), main.c) $(addprefix $(SRC_DIR), rgb.c) \
$(addprefix $(SRC_DIR), parsing.c) #$(addprefix $(SRC_DIR), key_handling.c)


OBJ_DIRS		=	$(OBJ_DIR) $(addprefix $(OBJ_DIR), $(SRC_DIR))

OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME):			$(OBJ) | $(SRC)
					printf 'Compiling $(NAME)\n'
					make bonus -C includes/libft/
					$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR) $(LINKS) -L ./includes/libft -lft


$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIRS)
					make dependecies
					printf "Compiling $(NAME) objects... %-33.33s\r" $(notdir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIRS):
					mkdir -p $@

all:				$(NAME)

dependecies:
					make -C $(MLX_PATH)

clean:
					if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi


fclean:				clean
					$(RM) $(NAME)
					make clean -C $(MLX_PATH)

re:					fclean all

.PHONY:				all clean fclean re

#NAME= fdf
#
#CC				=	cc
#
#CFLAGS			=	-Wall -Wextra -Werror 
#
#LINKS			=	-lm -lXext -lX11 -L$(MLX_PATH) -lmlx -lft
#
#MlX_PATH= /minilibx-linux/
#
#OBJ_DIR= objs/
#
#INCLUDES_DIR= includes/
#
#SOURCES_DIR= sources/
#
#SOURCES = main.c
#
#OBJ				=	$(SRC:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
#
#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
#
#$(NAME): $(OBJ)
#		$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDE_DIR) $(LINKS)
#
#all: $(NAME)
#
#dependencies:
#	make -C $(MlX_PATH)
#