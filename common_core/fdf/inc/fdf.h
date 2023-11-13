/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniblix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../lib/libft/inc/libft.h"

// Because X11 is stupid

# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_view
{
	int		scale;
	int		rotate_x;
	int		rotate_y;
	int		rotate_z;
	int		move_x;
	float	move_y;
	float	move_z;
	bool	parralel_projection;
	bool	render_text;
}	t_view;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

typedef struct s_pointf {
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}	t_pointf;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_view		view;
	t_pointf	*points;
	t_pointf	*points_view;
	int			size;
	int			total_points;
}	t_data;

struct s_norm
{
	t_img		img;
	float		width;
	float		height;
};

// args.c
int				ft_parse_args(int argc, char **argv, t_pointf ***dst);

// args2.c
t_pointf		**ft_realloc_dst(t_pointf ***dst, int idx);
int				ft_args2(int size, int tmp, t_pointf ***dst, int idx);

// close.c
int				ft_close(t_data *data, int code);

// dimensions.c
void			ft_calculate_dimensions(t_pointf *points, int point_amount,
					float *width, float *height);

// draw_line.c
struct	s_dl
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
};

void			ft_draw_line(void *img, t_pointf a, t_pointf b, uint32_t color);

// img.c

t_img			ft_new_img(t_data *data);

// handle_key.c
int				handle_key(int keycode, t_data *param);

// handle_mouse.c
int				handle_mouse(int button, int x, int y, t_data *param);

// pm2a.c
t_pointf		*ft_pm2a(t_pointf **data, int length, int *total_points);

// point.c
t_point			ft_point(int x, int y);
t_pointf		ft_pointf(float x, float y, float z);

// project.c
void			project(t_pointf *point, float focal_length,
					float distance_to_camera);

// render.c
void			ft_render(t_data *data);
void			ft_would_dimension(t_data *data, int *height, int *width);

// render_text.c
void			ft_render_text(t_data *data);

// rgb.c
uint32_t		ft_rgb(uint8_t r, uint8_t g, uint8_t b);

// rotate.c
void			rotate_x(t_pointf *point, float angle);
void			rotate_y(t_pointf *point, float angle);
void			rotate_z(t_pointf *point, float angle);

// scale.c
void			scale(t_pointf *point, float sx, float sy, float sz);

// set_pixel.c
void			ft_set_pixel(t_img *data, float x, float y, int color);

// translate.c
void			translate(t_pointf *point, t_view view);

#endif
