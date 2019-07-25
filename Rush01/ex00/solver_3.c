/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver_3.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 22:34:27 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 22:46:25 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_check_top(int **tab_value, int **tab_condition, int size, int x1);
int		ft_check_bottom(int **tab_value, int **tab_condition, int size, int x1);
int		check_diff(int **tab, int size);
void	debug_tab_int(int **tab_value);

int		ft_check_left(int **tab_value, int **tab_condition, int size, int y1)
{
	int x;
	int max;
	int count;

	max = 0;
	count = 0;
	x = -1;
	while (++x < size)
	{
		if (tab_value[y1][x] > max)
		{
			count++;
			max = tab_value[y1][x];
		}
	}
	if (tab_condition[2][y1] != count)
		return (0);
	return (1);
}

int		ft_check_right(int **tab_value, int **tab_condition, int size, int y1)
{
	int x;
	int max;
	int count;

	max = 0;
	count = 0;
	x = size;
	while (--x > -1)
	{
		if (tab_value[y1][x] > max)
		{
			count++;
			max = tab_value[y1][x];
		}
	}
	if (tab_condition[3][y1] != count)
		return (0);
	return (1);
}

int		ft_check_global(int **tab_value, int **tab_condition, int size)
{
	int x1;
	int y1;

	y1 = -1;
	while (++y1 < size)
	{
		x1 = -1;
		while (++x1 < size)
		{
			if (y1 == 0)
				if (ft_check_top(tab_value, tab_condition, size, x1) == 0)
					return (0);
			if (y1 == 1)
				if (ft_check_bottom(tab_value, tab_condition, size, x1) == 0)
					return (0);
			if (y1 == 2)
				if (ft_check_left(tab_value, tab_condition, size, x1) == 0)
					return (0);
			if (y1 == 3)
				if (ft_check_right(tab_value, tab_condition, size, x1) == 0)
					return (0);
		}
	}
	return (1);
}

int		tab_increment_2(int **tab_value, int *x, int *y, int **tab_mask)
{
	int size;

	size = 4;
	tab_value[*y][*x] = (tab_mask[*y][*x] == 0) ? 1 : tab_value[*y][*x];
	*x = *x - 1;
	if (*x < 0)
	{
		*x = size - 1;
		*y = *y - 1;
	}
	if (*y < 0)
		return (0);
	tab_value[*y][*x] = (tab_mask[*y][*x] == 0) ?
		tab_value[*y][*x] + 1 : tab_value[*y][*x];
	return (1);
}

void	tab_increment(int **tab_value, int **tab_mask,
		int **tab_cond, int size)
{
	int x;
	int y;

	x = size - 1;
	y = size - 1;
	while (tab_value[0][0] != 5)
	{
		tab_value[y][x] = (tab_mask[y][x] == 0) ?
			tab_value[y][x] + 1 : tab_value[y][x];
		while ((tab_value[y][x] > 4 || tab_mask[y][x] == 1)
				&& tab_value[0][0] != 5)
			if (tab_increment_2(tab_value, &x, &y, tab_mask) == 0)
				break ;
		if (check_diff(tab_value, size) == 1 &&
				ft_check_global(tab_value, tab_cond, size) == 1)
		{
			debug_tab_int(tab_value);
			return ;
		}
		if (y < 0)
			break ;
		y = size - 1;
		x = size - 1;
	}
	write(1, "Error\n", 6);
}
