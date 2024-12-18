/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:42:14 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 16:58:53 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	ft_numbercount(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

int	parseo(int argc, char *argv[])
{
	int		i;
	int		y;
	char	*ver;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		ver = argv[i];
		y = 0;
		while (ver[y] != '\0')
		{
			if (ver[y] == ' ')
			{
				count = count + ft_numbercount(ver, ' ') - 1;
				break ;
			}
			y++;
		}
		count++;
		i++;
	}
	return (count);
}
