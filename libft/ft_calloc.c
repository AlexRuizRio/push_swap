/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:00:23 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/03/14 17:38:41 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;
	size_t			len;

	len = count * size;
	str = malloc(len);
	i = 0;
	if (str == 0)
		return (0);
	while (len--)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
