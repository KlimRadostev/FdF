/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:06:40 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/19 17:00:29 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	grow_map(t_li *h, int x, int y)
{
	h->map[y][x].y = h->map[y][x].y * 2 - 300;
	h->map[y][x].x = h->map[y][x].x * 2 - 300;
}

static void	shrink_map(t_li *h, int x, int y)
{
	h->map[y][x].y = h->map[y][x].y / 2 + 250;
	h->map[y][x].x = h->map[y][x].x / 2 + 250;
}

static void	features(t_li *h, int x, int y, int key)
{
	(key == 126) ? h->map[y][x].y -= 50 : 1;
	(key == 123) ? h->map[y][x].x -= 50 : 1;
	(key == 125) ? h->map[y][x].y += 50 : 1;
	(key == 124) ? h->map[y][x].x += 50 : 1;
	(key == 69) ? h->map[y][x].y -= h->map[y][x].alpha * 2 : 1;
	(key == 78) ? h->map[y][x].y += h->map[y][x].alpha * 2 : 1;
}

void		move_sides(int key, t_li *h)
{
	int	x;
	int	y;

	y = -1;
	while (++y < h->alg->h)
	{
		x = -1;
		while (++x < h->alg->w)
			features(h, x, y, key);
	}
}

void		shrink_grow(int key, t_li *h)
{
	int			x;
	int			y;

	y = -1;
	if (key == 82)
	{
		while (++y < h->alg->h)
		{
			x = -1;
			while (++x < h->alg->w)
				grow_map(h, x, y);
		}
		h->kai = h->kai + 1;
	}
	if (key == 83 && h->kai > 1)
	{
		while (++y < h->alg->h)
		{
			x = -1;
			while (++x < h->alg->w)
				shrink_map(h, x, y);
		}
		h->kai = h->kai - 1;
	}
}
