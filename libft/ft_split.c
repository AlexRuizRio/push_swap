/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:10 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/03/15 20:34:39 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_wordcount(char const *s, char c)
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

static	void	ft_freelst(char **lst, int i)
{
	while (i >= 0)
		free(lst[i--]);
	free (lst);
}

static	char	**ft_wordsplit(char **lst, char const *s, char c, int i)
{
	size_t	wlen;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				wlen = ft_strlen(s);
			else
				wlen = ft_strchr(s, c) - s;
			lst[i] = ft_substr(s, 0, wlen);
			if (lst[i] == NULL)
			{
				ft_freelst(lst, i - 1);
				return (NULL);
			}
			s += wlen;
			i++;
		}
	}
	lst[i] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;

	i = 0;
	lst = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	lst = ft_wordsplit(lst, s, c, i);
	if (!lst)
		return (NULL);
	else
		return (lst);
}
