/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:03:14 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/18 16:21:55 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}
