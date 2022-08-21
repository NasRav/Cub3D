#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <fcntl.h>
# include <math.h>
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define R_RIGHT 124
# define R_LEFT 123
# define ESC 53

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
}				t_vars;

typedef struct s_params
{
	int			res_width;
	int			res_height;
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	char		*text_spr;
	int			c_floor;
	int			c_celling;
	char		**map;
	int			map_h;
	int			map_w;
	float		f_plr_x;
	float		f_plr_y;
	int			i_plr_x;
	int			i_plr_y;
	char		dir;
	int			count_spr;
}				t_params;

typedef struct s_plr
{
	float		camera_x;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		dlt_dist_x;
	float		dlt_dist_y;
	float		perp_wall_dist;
	float		ray_dir_x;
	float		ray_dir_y;
	float		player_x;
	float		player_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			wall_side;
	float		side_dist_x;
	float		side_dist_y;
	int			draw_height;
	int			draw_start;
	int			draw_end;
	int			hit;
	float		wall_x;
	int			color;
	float		step;
	int			tex_x;
	int			tex_y;
	int			tex_width;
	int			tex_height;
	float		tex_pos;
	float		*buf;
}				t_plr;

typedef struct s_sprite
{
	float		x;
	float		y;
	float		dist;
}				t_sprite;

typedef struct s_raycast
{
	t_sprite	*sprites;
	int			num_sprites;
	float		sprite_x;
	float		sprite_y;
	float		inv_det;
	float		transform_x;
	float		transform_y;
	int			sprite_screen_x;
	int			tex_height;
	int			tex_width;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			stripe;
	int			tex_x;
	int			tex_y;
	int			color;
}				t_raycast;

typedef struct s_all
{
	t_vars		*win;
	t_data		*img;
	t_params	*params;
	t_plr		*plr;
	t_data		*no;
	t_data		*so;
	t_data		*we;
	t_data		*ea;
	t_data		*spr;
	t_raycast	*raycast;
	char		**map;
	int			current_color;
	int			screen_save;
	int			fd;
}				t_all;

int				argv_check(int argc, char **argv);
t_all			*pars_all(char *filename);
int				open_file(char *filename);
t_list			*read_file(int fd);
t_params		*pars_file(t_list **file);
void			init_all(t_params *param);
int				struct_is_full(t_params *param);
void			skip_whitespaces(char **s);
void			get_resolution(char *s, t_params *param, int len);
void			pars_textures(char *s, t_params *param, int side);
void			get_color(char *s, t_params *param, int type);
void			check_trash(char *s);
void			init_map_params(t_list *tmp, t_params *param);
void			error_handler(int type_error, int error_code);
void			to_zero(t_params *param);
void			check_bound(t_params *param);
void			max_width(t_params *param);
char			**copy_map(t_params *param);
void			free_new_map(t_params *param, char **new_map);
t_list			*skip_empty(t_list *list);
void			find_plr(char **map, t_params *param, int i);
void			find_sprites(t_params *param);
float			calc_dist(float expr);
void			check_valid(t_params *p, int i, int j, char dir_plr);
void			flood(t_params *param);
void			flood_fill(char **map, t_params *param, int x, int y);
void			game(t_all *all, int argc);
void			my_mlx_init(t_all *all);
void			sprites_init(t_all *all);
void			my_plr_init(t_all *all);
void			start_init(t_all *all, int x);
void			sprites_to_array(t_all *all);
void			sort_sprites(t_sprite *sprites, int count);
void			read_text(t_all *all);
void			draw_all(t_all *all);
void			check_step(t_plr *plr);
void			check_hit(t_all *all, t_plr *plr);
void			paint_wall(t_all *all, int x, int y, t_plr *p);
void			paint_sprites(t_all *all);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
int				create_rgb(int r, int g, int b);
int				key_press(int key, t_all *all);
void			screen_save(t_all *all);
void			my_image_init(t_all *all);

#endif
