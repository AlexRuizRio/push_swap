/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:34:48 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/03/13 15:34:50 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	const char	*x;
	const char	*y;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = len;
		x = haystack;
		y = needle;
		while (i-- > 0 && *x && *y && *x == *y)
		{
			x++;
			y++;
		}
		if (*y == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
