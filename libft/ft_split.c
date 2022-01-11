/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:37:26 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 18:37:30 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strings_count(char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
		{
			k++;
			continue;
		}
		while (s[k] != c && s[k])
			k++;
		i++;
	}
	return (i);
}

static int	freee(char **tab, int i)
{
	while (i--)
	{
		free(tab[i]);
	}
	free(tab);
	return (-1);
}

static int	make_lines(char const *s, char **p, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
		{
			k++;
			continue;
		}
		while ((s[k] != c && s[k]))
		{
			k++;
			j++;
		}
		if (!(p[i] = (char*)malloc(sizeof(char) * (j + 1))))
			return (freee(p, i - 1));
		i++;
		j = 0;
	}
	return (0);
}

static int	copy_lines(char const *s, char **p, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
		{
			k++;
			continue;
		}
		while (s[k] != c && s[k])
		{
			p[i][j] = s[k];
			j++;
			k++;
		}
		p[i][j] = '\0';
		i++;
		j = 0;
	}
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**p;
	int		strcount;

	if (!s)
		return (NULL);
	strcount = ft_strings_count(s, c);
	if (!(p = (char **)malloc(sizeof(char*) * (strcount + 1))))
		return (NULL);
	p[strcount] = NULL;
	if (make_lines(s, p, c) == -1)
		return (NULL);
	copy_lines(s, p, c);
	return (p);
}
