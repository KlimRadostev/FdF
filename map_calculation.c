/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:08:50 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/19 17:16:24 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void	variable_initialize(t_x *x, int sq_fm, t_li *h)
{
	x->hg = 0;
	x->three_d = 250;
	x->three_decrease = x->three_d / h->alg->h;
	x->three_increment = 150 / h->alg->w;
	x->store_h = sq_fm;
}

static void	initialize_mid(t_x *x, int sq_fm, t_li *h)
{
	x->w = -1;
	x->store_w = 0;
	x->three_dd = 100;
}

static void	increment_low(t_x *x, int sq_fm, char *line)
{
	x->store_h += sq_fm;
	x->hg++;
	x->three_d -= x->three_decrease;
	free(line);
}

static void	middle_section(t_x *x, int sq_fm, t_li *h, char *line)
{
	x->store_w += sq_fm;
	x->three_dd += x->three_increment;
	h->map[x->hg][++x->w].x = x->three_d + x->store_w;
	h->map[x->hg][x->w].y = x->three_dd * 1.5 +
		x->store_h - (ft_atoi(line) * 5);
	h->map[x->hg][x->w].alpha = ft_atoi(line);
}

void		calculate_map(int fd, t_li *h)
{
	t_x		*x;
	char	*line;
	int		sq_fm;
	int		i;

	x = (t_x *)ft_memalloc(sizeof(t_x) * 1);
	sq_fm = (h->alg->w < h->alg->h) ? SIZE / h->alg->h : SIZE / h->alg->w;
	variable_initialize(x, sq_fm, h);
	while (get_next_line(fd, &line) == 1)
	{
		initialize_mid(x, sq_fm, h);
		i = 0;
		while (line[i])
		{
			if (line[i] != ' ' && line[i])
			{
				middle_section(x, sq_fm, h, &line[i]);
				while (line[i] != ' ' && line[i])
					i++;
			}
			(line[i]) ? i++ : 1;
		}
		increment_low(x, sq_fm, line);
	}
	free(x);
}
