/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:28:59 by ple-lez           #+#    #+#             */
/*   Updated: 2016/07/06 14:04:24 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			ft_color(t_env *env, int n)
{
	int		color;

	if (env->side)
	{
		if (env->ray->stepy < 0)
			color = RED;
		else
			color = GREEN;
	}
	else
	{
		if (env->ray->stepx < 0)
			color = GOLD;
		else
			color = BLUE;
	}
	if (n < env->ray->start)
		color = CYAN;
	else if (n > env->ray->end)
		color = BROWN;
	else if (env->map[env->mapy][env->mapx] == 2)
		color /= 2;
	return (color);
}

int			ft_proper_exit(t_env *env)
{
	ft_exit(0, env);
	return (0);
}

static void	ft_rotate(t_env *env, int keycode)
{
	int		coef;
	double	dirxtmp;
	double	planextmp;

	if (keycode == LEFT)
		coef = 1;
	else
		coef = -1;
	if (keycode == LEFT || keycode == RIGHT)
	{
		dirxtmp = env->cam->dirx;
		planextmp = env->cam->planex;
		env->cam->dirx = dirxtmp * cos(0.16 * coef)
			- env->cam->diry * sin(0.16 * coef);
		env->cam->diry = dirxtmp * sin(0.16 * coef)
			+ env->cam->diry * cos(0.16 * coef);
		env->cam->planex = planextmp * cos(0.16 * coef)
			- env->cam->planey * sin(0.16 * coef);
		env->cam->planey = planextmp * sin(0.16 * coef)
			+ env->cam->planey * cos(0.16 * coef);
	}
}

static void	ft_open_door(t_env *env)
{
	if (env->map[(int)(env->cam->posy + env->cam->diry)]
			[(int)(env->cam->posx + env->cam->dirx)] == 2)
		env->map[(int)(env->cam->posy + env->cam->diry)]
			[(int)(env->cam->posx + env->cam->dirx)] = 3;
	else if (env->map[(int)(env->cam->posy + env->cam->diry)]
			[(int)(env->cam->posx + env->cam->dirx)] == 3)
		env->map[(int)(env->cam->posy + env->cam->diry)]
			[(int)(env->cam->posx + env->cam->dirx)] = 2;
}

int			ft_key_press(int keycode, t_env *env)
{
	if (keycode == ESC)
		ft_exit(0, env);
	if (keycode == UP)
	{
		if (ISFREE(env->map[(int)(env->cam->posy)][(int)(env->cam->posx
						+ env->cam->dirx * 0.27)]))
			env->cam->posx += env->cam->dirx * 0.27;
		if (ISFREE(env->map[(int)(env->cam->posy + env->cam->diry)]
				[(int)(env->cam->posx)]))
			env->cam->posy += env->cam->diry * 0.27;
	}
	if (keycode == DOWN)
	{
		if (env->map[(int)(env->cam->posy - env->cam->diry
					* 0.27)][(int)(env->cam->posx)] == 0)
			env->cam->posy -= env->cam->diry * 0.27;
		if (env->map[(int)(env->cam->posy)][(int)(env->cam->posx
				- env->cam->dirx * 0.27)] == 0)
			env->cam->posx -= env->cam->dirx * 0.27;
	}
	if (keycode == SPACE)
		ft_open_door(env);
	ft_rotate(env, keycode);
	ft_draw(env);
	return (0);
}
