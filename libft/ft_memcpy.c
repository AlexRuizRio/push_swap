/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:11:43 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/03/12 11:11:46 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		ptr[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
