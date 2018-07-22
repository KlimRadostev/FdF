/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:05:13 by kradoste          #+#    #+#             */
/*   Updated: 2018/07/19 16:16:53 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	deal_key(int key, t_li *h)
{
	if (key == 53)
		exit(0);
	move_sides(key, h);
	shrink_grow(key, h);
	mlx_clear_window(h->mlx_ptr, h->win_ptr);
	draw_map(h);
	return (0);
}

static void	free_all(t_li *h)
{
	int	x;

	x = h->alg->h;
	while (--x >= 0)
		free(h->map[x]);
	free(h->map);
	free(h->alg);
	free(h);
}

static t_li	*allocate_memory(int fd, t_li *h)
{
	if (!(h = (t_li *)ft_memalloc(sizeof(t_li))))
	{
		ft_putstr("Error\n");
		return ((void *)0);
	}
	if (!(h->alg = (t_ca *)ft_memalloc(sizeof(t_ca))))
	{
		ft_putstr("Error\n");
		return ((void *)0);
	}
	if (!(h->map = memory_make(fd, h)))
	{
		ft_putendl("Error");
		return ((void *)0);
	}
	return (h);
}

int			main(int ac, char **argv)
{
	t_li	*h;
	int		fd;

	if (ac != 2)
		ft_putstr("Error\n");
	if (ac == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0 || !(h = allocate_memory(fd, h)))
			return (0);
		h->kai = 1;
		close(fd);
		h->mlx_ptr = mlx_init();
		h->win_ptr = mlx_new_window(h->mlx_ptr, 2 * SIZE + 500,
									2 * SIZE + 100, "mlx 42");
		fd = open(argv[1], O_RDONLY);
		calculate_map(fd, h);
		close(fd);
		draw_map(h);
		mlx_hook(h->win_ptr, 2, 5, deal_key, h);
		mlx_loop(h->mlx_ptr);
	}
	free(h);
	return (0);
}
