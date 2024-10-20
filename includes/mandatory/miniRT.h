/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:31 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:52 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../../libft/libft.h"
# include "mat.h"
# include "vec.h"
# include "ray.h"

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2
# define HYPERBOLD	3
# define LIGHT		4

# define WRONG_ARG	1
# define OPEN_FILE	2
# define WRONG_FORM	3
# define NOT_A_NUM	4
# define NO_CAMERA	5
# define SIZE_MATCH	5
# define OUT_OF_BND	6
# define INVAL_RES	7
# define NORM_FAIL	7

# define ON_KEYDOWN	2
# define ON_MOUSE	6
# define ON_DESTROY	17

# define WIDTH		160
# define ASPECT		0.5625
# define MIN_T		0.01
# define RATIO		10

typedef struct s_axis
{
	double	x_ax;
	double	y_ax;
	double	z_ax;
}	t_axis;

typedef struct s_color
{
	char	r;
	char	g;
	char	b;
}	t_color;

typedef struct s_a
{
	t_vec	color;
}	t_a;

typedef struct s_c
{
	t_vec	point;
	t_vec	view;
	t_vec	up;
	t_mat	on_basis;
	double	fov;
}	t_c;

typedef struct s_l
{
	t_vec	point;
	t_vec	color;
}	t_l;

typedef struct s_sp
{
	t_vec	center;
	t_vec	color;
	double	rad;
}	t_sp;

typedef struct s_pl
{
	t_vec	point;
	t_vec	normal;
	t_vec	color;
}	t_pl;

typedef struct s_cy
{
	t_vec	center;
	t_vec	normal;
	double	rad;
	double	h;
	t_vec	color;
}	t_cy;

typedef struct s_hb
{
	t_vec	center;
	t_vec	normal;
	t_vec	scaler;
	t_vec	color;
	t_mat	lin_trans;
	t_mat	lin_trans_tr;
	double	h;
}	t_hb;

typedef struct s_obj
{
	int		obj_total;
	t_a		a;
	t_c		c;
	t_list	*l;
	t_list	*obj;
}	t_obj;

typedef struct s_viewport
{
	double	w;
	double	h;
	double	d;
	t_vec	w_vec;
	t_vec	h_vec;
	t_vec	w_unit_vec;
	t_vec	h_unit_vec;
	t_vec	upper_left;
	t_vec	upper_left_pixel;
}	t_viewport;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
}	t_mlx_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	int			mouse_x;
	int			mouse_y;
	int			img_w;
	int			img_h;
	int			total_w;
	int			total_h;
	int			ratio;
	double		aspect;
	t_mlx_data	mlx;
	t_img		img;
	t_obj		obj;
	t_viewport	vp;
}	t_data;

// parse
t_vec	str_to_vec(char *str);
void	open_rt_file(int ac, char **av, int *fd);
void	parse_rt_file(t_data *img, int fd);

// hittable
int		chk_hittable_sp(t_ray *ray, t_sp *sp);
int		chk_hittable_pl(t_ray *ray, t_pl *pl);
int		chk_hittable_cy(t_ray *ray, t_cy *cy);
int		chk_hittable_hb(t_ray *ray, t_hb *hb);
double	find_point_pl(t_ray *ray, t_vec point, t_vec normal);
double	solve_root_equation(double *e);

// check_hittable
int		check_hittable_to_all_obj(t_data *data, t_ray *ray);

// view
void	set_img_size(t_data *data);
void	set_viewport(t_viewport *vp, t_data *data);

// utils
double	min_d(double a, double b);
double	max_d(double a, double b);
t_vec	trim_max_light(t_vec light);
void	gen_lin_trans_mat(t_hb *hb);

// main
void	handling_error(int flag);
void	set_data_init(t_data *data);
void	shoot_ray_to_pixel(t_data *data);
void	set_camera_origin(t_data *data, t_obj *obj);

#endif
