/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:08:35 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/19 16:45:43 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	determine_color(t_po *p1, t_li *h)
{
	int	g;
	int	s;
	int	dif;

	if (h->alg->god_num == h->alg->god_num - p1->alpha)
		p1->col = h->l;
	else if (!(h->alg->god_num - p1->alpha))
		p1->col = h->h;
	else
	{
		if (h->l > h->h)
		{
			g = h->l;
			s = h->h;
		}
		else
		{
			g = h->h;
			s = h->l;
		}
		dif = g - s;
		p1->col = g - (dif / ((h->alg->god_num + 1) - ft_abs(p1->alpha)));
	}
}

void		draw_map(t_li *all)
{
	int	h;
	int	w;

	h = -1;
	all->l = 0xFFFFFF;
	all->h = 0xFF0000;
	while (++h < all->alg->h)
	{
		w = -1;
		while (++w < all->alg->w)
		{
			determine_color(&all->map[h][w], all);
			if (w - 1 >= 0)
				draw_line(all->map[h][w], all->map[h][w - 1], all);
			if (h - 1 >= 0)
				draw_line(all->map[h][w], all->map[h - 1][w], all);
		}
	}
}
