/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:01:49 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/19 16:30:54 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# define SIZE 600

typedef struct	s_ma
{
	int	w;
	int	hg;
	int	store_w;
	int	store_h;
	int	three_d;
	int	three_decrease;
	int	three_dd;
	int	three_increment;
}				t_x;

typedef struct	s_god_num
{
	int	w;
	int	h;
	int	god_num;
}				t_ca;

typedef struct	s_map
{
	double	x;
	double	y;
	double	alpha;
	int		col;
}				t_po;

typedef struct	s_size
{
	int		l;
	int		h;
	void	*mlx_ptr;
	void	*win_ptr;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		x;
	int		y;
	t_po	p1;
	t_po	p2;
	t_po	**map;
	t_ca	*alg;
	int		kai;
}				t_li;

void			draw_line(t_po p1, t_po p2, t_li *h);
t_po			**memory_make(int fd, t_li *h);
void			move_sides(int key, t_li *h);
void			draw_map(t_li *all);
void			calculate_map(int fd, t_li *h);
void			shrink_grow(int key, t_li *h);

#endif
