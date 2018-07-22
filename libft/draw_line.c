/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:38:19 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/18 17:04:38 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_x(int d, int d1, int d2, t_li *h)
{
	int		i;
	int		dif;
	int		g;
	int		color;

	i = 1;
	dif = h->p1.col - h->p2.col;
	g = dif / h->dx;
	(h->p1.col > h->p2.col) ? (g *= -1) : 1;
	color = h->p1.col;
	while (i <= h->dx)
	{
		if (d > 0)
		{
			d += d2;
			h->y += h->sy;
		}
		else
			d += d1;
		mlx_pixel_put(h->mlx_ptr, h->win_ptr, h->x, h->y, color);
		i++;
		h->x += h->sx;
		color += g;
	}
}

static void	draw_line_y(int d, int d1, int d2, t_li *h)
{
	int		i;
	int		dif;
	int		g;
	int		color;

	i = 1;
	dif = ft_abs(h->p1.col - h->p2.col);
	g = dif / h->dx;
	(h->p1.col > h->p2.col) ? (g *= -1) : 1;
	color = h->p1.col;
	while (i <= h->dy)
	{
		if (d > 0)
		{
			d += d2;
			h->x += h->sx;
		}
		else
			d += d1;
		mlx_pixel_put(h->mlx_ptr, h->win_ptr, h->x, h->y, color);
		i++;
		h->y += h->sy;
		color += g;
	}
}

void		draw_line(t_po p1, t_po p2, t_li *h)
{
	h->dx = ft_abs(p2.x - p1.x);
	h->dy = ft_abs(p2.y - p1.y);
	h->sx = p2.x >= p1.x ? 1 : -1;
	h->sy = p2.y >= p1.y ? 1 : -1;
	mlx_pixel_put(h->mlx_ptr, h->win_ptr, p1.x, p1.y, p1.col);
	h->p1 = p1;
	h->p2 = p2;
	if (h->dy <= h->dx)
	{
		h->x = p1.x + h->sx;
		h->y = p1.y;
		draw_line_x((h->dy << 1) - h->dx, h->dy << 1, (h->dy - h->dx) << 1, h);
	}
	else
	{
		h->y = p1.y + h->sy;
		h->x = p1.x;
		draw_line_y((h->dx << 1) - h->dy, h->dx << 1, (h->dx - h->dy) << 1, h);
	}
}
