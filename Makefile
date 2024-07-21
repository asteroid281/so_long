SRCS =	map_check.c	\
		map_create.c	\
		so_long.c	\
		errors.c	\
		map_path_check.c	\
		graphs.c	\
		move_keys.c	\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

MLX_PATH = minilibx
LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf

MLX = libmlx.a
LIBFT = libft.a
FT_PRINTF = libftprintf.a

LIBRARY = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

MLX_ARCH = $(MLX_PATH)/$(MLX)
LIBFT_ARCH = $(LIBFT_PATH)/$(LIBFT)
FT_PRINTF_ARCH = $(FT_PRINTF_PATH)/$(FT_PRINTF)

all: $(NAME)

$(NAME): $(OBJS)
	make -s -C $(MLX_PATH)
	make -s -C $(LIBFT_PATH)
	make -s -C $(FT_PRINTF_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCH) $(FT_PRINTF_ARCH) $(LIBRARY) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(FT_PRINTF_PATH) clean
	@make -s -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
