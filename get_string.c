/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:45:42 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/12/18 21:26:24 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_strlong(const char *str)
{
	long	result;
	int		sig;

	result = 0;
	sig = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		else
			sig = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sig);
}

long	ft_isnumber(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!*str || !ft_isdigit(*str))
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (-1);
}

int	contains_space(const char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

int	store_numbers(char **tmp, long *argi, int *z)
{
	int	j;

	j = 0;
	while (tmp[j])
	{
		if (!ft_isnumber(tmp[j]))
		{
			while (tmp[j])
				free(tmp[j++]);
			free(tmp);
			return (-1);
		}
		argi[(*z)++] = ft_strlong(tmp[j]);
		free(tmp[j++]);
	}
	free(tmp);
	return (0);
}

int	sacarstring(int argc, char *argv[], long *argi)
{
	int		i;
	int		z;
	char	**tmp;

	i = 1;
	z = 0;
	while (i < argc)
	{
		if (contains_space(argv[i]))
		{
			tmp = ft_split(argv[i], ' ');
			if (tmp == NULL || store_numbers(tmp, argi, &z) == -1)
				return (write(2, "Error\n", 6));
		}
		else
		{
			if (!ft_isnumber(argv[i]))
				return (write(2, "Error\n", 6));
			argi[z++] = ft_strlong(argv[i]);
		}
		i++;
	}
	return (0);
}
