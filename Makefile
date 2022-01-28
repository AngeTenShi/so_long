NAME		=	so_long
CC			=	gcc -g
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lz
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/map_checker_utils.c \
				src/map_checker_utils2.c \
				src/map_checker.c \
				src/init.c \
				src/main.c \

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "Objects Files has been removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Binary file has been removed."

re:			fclean all

.PHONY:		all clean fclean re
