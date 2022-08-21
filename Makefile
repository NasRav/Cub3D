NAME =		cub3D

CC =		gcc
RM =		/bin/rm -f
CFLAGS =	-Wall -Wextra -Werror

SRCS =		srcs/main.c \
			srcs/argv_check.c \
			srcs/calc_dist.c \
			srcs/error_handler.c \
			srcs/flood_fill.c \
			srcs/key_handler.c \
			srcs/init_all.c \
			srcs/my_mlx_init.c \
			srcs/my_mlx_pixel_put.c \
			srcs/paint_sprites.c \
			srcs/get_color.c \
			srcs/parser.c \
			srcs/pars_file.c \
			srcs/pars_map2.c \
			srcs/get_resolution.c \
			srcs/pars_textures.c \
			srcs/read_file.c \
			srcs/read_text.c \
			srcs/screen_save.c \
			srcs/sortsprites.c \
			srcs/start.c \
			srcs/start_pars_map2.c \
			srcs/start_pars_map.c \
			srcs/start_utils.c

OBJS =		$(SRCS:.c=.o)


.c.o :		includes/cub3d.h libft/libft.h
			$(CC) $(CFLAGS) -Ilibft -Iminilibx_mms_20200219 -Iincludes \
			-c $< -o $(<:.c=.o)


$(NAME) :	$(OBJS)
			make -C libft
			cp libft/libft.a .
			make -C minilibx_mms_20200219
			cp minilibx_mms_20200219/libmlx.dylib .
			$(CC) -o $(NAME) $(OBJS) libft.a libmlx.dylib -framework OpenGL \
			-framework AppKit


all :		$(NAME)

clean :
			$(RM) $(OBJS) libft.a libmlx.dylib
			make fclean -C libft
			make clean -C minilibx_mms_20200219

fclean :	clean
			$(RM) $(NAME)

re :		fclean \
			all

.PHONY :	all clean fclean re
