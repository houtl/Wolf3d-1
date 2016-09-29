/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:24:15 by ple-lez           #+#    #+#             */
/*   Updated: 2016/07/06 13:10:14 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static void		ft_calc_delta(t_env *env)
{
	env->ray->deltay = sqrt(1 + (env->ray->dirx * env->ray->dirx)
			/ (env->ray->diry * env->ray->diry));
	env->ray->deltax = sqrt(1 + (env->ray->diry * env->ray->diry)
			/ (env->ray->dirx * env->ray->dirx));
	if (env->ray->dirx < 0)
	{
		env->ray->stepx = -1;
		env->ray->distx = (env->ray->posx - env->mapx) * env->ray->deltax;
	}
	else
	{
		env->ray->stepx = 1;
		env->ray->distx = (env->mapx + 1.0 - env->ray->posx) * env->ray->deltax;
	}
	if (env->ray->diry < 0)
	{
		env->ray->stepy = -1;
		env->ray->disty = (env->ray->posy - env->mapy) * env->ray->deltay;
	}
	else
	{
		env->ray->stepy = 1;
		env->ray->disty = (env->mapy + 1.0 - env->ray->posy) * env->ray->deltay;
	}
}

static void		ft_init_ray(t_env *env, int n)
{
	env->cam->relx = 2 * n / (double)LENGTH - 1;
	env->ray->posx = env->cam->posx;
	env->ray->posy = env->cam->posy;
	env->mapx = (int)env->ray->posx;
	env->mapy = (int)env->ray->posy;
	env->ray->dirx = env->cam->dirx + env->cam->planex * env->cam->relx;
	env->ray->diry = env->cam->diry + env->cam->planey * env->cam->relx;
	env->hit = 0;
	ft_calc_delta(env);
}

static void		ft_draw_line(t_env *env, int i)
{
	int			j;
	int			pos;
	int			color;

	j = -1;
	while (++j < HEIGHT)
	{
		color = ft_color(env, j);
		pos = (i * (env->bpp / 8)) + (j * env->size);
		env->img_addr[pos] = mlx_get_color_value(env->mlx, color);
		env->img_addr[pos + 1] = mlx_get_color_value(env->mlx, color >> 8);
		env->img_addr[pos + 2] = mlx_get_color_value(env->mlx, color >> 16);
	}
}

static void		ft_calc_ray(t_env *env, int i)
{
	if (!env->side)
		env->cam->distance = (env->mapx - env->ray->posx
				+ (1 - env->ray->stepx) / 2) / env->ray->dirx;
	else
		env->cam->distance = (env->mapy - env->ray->posy
				+ (1 - env->ray->stepy) / 2) / env->ray->diry;
	env->ray->len = (int)(HEIGHT / env->cam->distance);
	env->ray->start = -(env->ray->len) / 2 + HEIGHT / 2;
	env->ray->end = env->ray->len / 2 + HEIGHT / 2;
	if (env->ray->start < 0)
		env->ray->start = 0;
	if (env->ray->end >= HEIGHT)
		env->ray->end = HEIGHT - 1;
	ft_draw_line(env, i);
}

void			ft_diff_analys(t_env *env)
{
	int		i;

	i = -1;
	while (++i < LENGTH)
	{
		ft_init_ray(env, i);
		while (!env->hit)
		{
			if (env->ray->distx < env->ray->disty)
			{
				env->ray->distx += env->ray->deltax;
				env->mapx += env->ray->stepx;
				env->side = 0;
			}
			else
			{
				env->ray->disty += env->ray->deltay;
				env->mapy += env->ray->stepy;
				env->side = 1;
			}
			if (!ISFREE(env->map[env->mapy][env->mapx]))
				env->hit = 1;
		}
		ft_calc_ray(env, i);
	}
}
