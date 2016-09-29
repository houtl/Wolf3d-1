/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:22:19 by ple-lez           #+#    #+#             */
/*   Updated: 2016/07/16 12:41:15 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static int	ft_wall(int i, int j)
{
	if (i == 0 || j == 0 || i == MAPY - 1 || j == MAPX - 1)
		return (1);
	if (i == 3 && j == 15)
		return (2);
	if (i == 12 && j == 6)
		return (2);
	if (i == 3 && j < 21 && j > 5)
		return (1);
	if (i == 6 && j < 18 && j > 8)
		return (1);
	if (i == 14 && j < 14 && j > 8)
		return (1);
	if (j == 3 && i > 8 && i < 16)
		return (1);
	if (j == 6 && i > 8 && i < 19)
		return (1);
	if (j == 9 && i > 12 && i < 15)
		return (1);
	if (j == 17 && i > 6 && i < 17)
		return (1);
	if (j == 20 && i > 16 && i < 21)
		return (1);
	return (0);
}

static void	ft_init_map(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	if (!(env->map = (int **)malloc(sizeof(int *) * MAPY)))
		ft_exit(-1, env);
	while (++i < MAPY)
		if (!(env->map[i] = (int *)malloc(sizeof(int) * MAPX)))
			ft_exit(-1, env);
	i = -1;
	j = -1;
	while (++i < MAPY)
	{
		while (++j < MAPX)
			env->map[i][j] = ft_wall(i, j);
		j = -1;
	}
}

t_env		*ft_init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if (!(env->cam = (t_cam *)malloc(sizeof(t_cam))))
		ft_exit(-1, env);
	if (!(env->ray = (t_ray *)malloc(sizeof(t_ray))))
		ft_exit(-1, env);
	env->cam->posx = 22;
	env->cam->posy = 12;
	env->cam->dirx = -1;
	env->cam->diry = 0;
	env->cam->planex = 0;
	env->cam->planey = 0.66;
	env->cam->rotspeed = 3.0;
	env->cam->movespeed = 5.0;
	env->redraw = 0;
	ft_init_map(env);
	return (env);
}
