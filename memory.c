/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:27:11 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/18 20:42:15 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	custom_wordcount(char *str, t_li *h)
{
	int	x;
	int	n;

	x = 0;
	n = 0;
	while (str[n])
	{
		if (!ft_isspace(str[n]))
			x++;
		if (ft_abs(ft_atoi(&str[n])) > h->alg->god_num)
			h->alg->god_num = ft_abs(ft_atoi(&str[n]));
		while (!ft_isspace(str[n]) && str[n + 1])
			n++;
		n++;
	}
	return (x);
}

t_po		**memory_make(int fd, t_li *h)
{
	char	*line;
	int		i;
	int		equality;

	h->alg->h = 0;
	h->alg->w = 0;
	h->alg->god_num = 0;
	i = -1;
	while (get_next_line(fd, &line) == 1)
	{
		if (h->alg->h++ == 0)
			h->alg->w = custom_wordcount(line, h);
		equality = custom_wordcount(line, h);
		if (equality != h->alg->w)
			return ((void *)0);
		free(line);
	}
	if (!(h->map = (t_po **)ft_memalloc(sizeof(t_po *) * (h->alg->h))))
		return ((void *)0);
	i = 0;
	while (i < h->alg->h)
		if (!(h->map[i++] = (t_po *)ft_memalloc(sizeof(t_po) * h->alg->w)))
			return ((void *)0);
	return (h->map);
}
