/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:18:58 by ple-lez           #+#    #+#             */
/*   Updated: 2016/07/06 14:04:46 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define GREEN 0x41d441
# define BROWN 0x905000
# define GRAY 0x191919
# define GOLD 0xfa9f1b
# define BLUE 0x003366
# define CYAN 0x29c2fd
# define RED 0xfd0c1f
# define HEIGHT 1200
# define LENGTH 1600
# define ANGLE 60
# define MAPX 24
# define MAPY 24
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPACE 49
# define ESC 53
# define ISFREE(x) (x == 0 || x == 3 ? 1 : 0)

typedef struct	s_cam
{
	double		relx;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		angle;
	double		planex;
	double		planey;
	double		distance;
	double		movespeed;
	double		rotspeed;
}				t_cam;

typedef struct	s_ray
{
	double		deltax;
	double		deltay;
	double		distx;
	double		disty;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	int			len;
	int			stepx;
	int			stepy;
	int			start;
	int			end;
}				t_ray;

typedef struct	s_env
{
	t_cam		*cam;
	t_ray		*ray;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			redraw;
	int			endian;
	int			**map;
	int			mapx;
	int			mapy;
	int			side;
	int			size;
	int			bpp;
	int			hit;
}				t_env;

t_env			*ft_init_env(void);
void			ft_draw(t_env *env);
void			ft_diff_analys(t_env *env);
int				ft_proper_exit(t_env *env);
void			ft_exit(int n, t_env *env);
int				ft_key_press(int keycode, t_env *env);
int				ft_color(t_env *env, int n);

#endif
