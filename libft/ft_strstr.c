/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:06:44 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/08 19:46:52 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k])
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
