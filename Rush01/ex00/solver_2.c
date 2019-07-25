/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver_2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 22:33:41 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 09:21:51 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		check_diff_vert(int **tab, int size)
{
	int x;
	int y;
	int i;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			i = size;
			while (--i > -1)
				if ((tab[y][x] == tab[y][i] && x != i) || tab[y][x] == 0)
					return (0);
		}
	}
	return (1);
}

int		check_diff_hort(int **tab, int size)
{
	int x;
	int y;
	int i;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			i = size;
			while (--i > -1)
				if (tab[y][x] == tab[i][x] && y != i)
					return (0);
		}
	}
	return (1);
}

int		check_diff(int **tab, int size)
{
	if (check_diff_vert(tab, size))
		if (check_diff_hort(tab, size))
			return (1);
	return (0);
}

int		ft_check_top(int **tab_value, int **tab_condition, int size, int x1)
{
	int y;
	int max;
	int count;

	max = 0;
	count = 0;
	y = -1;
	while (++y < size)
	{
		if (tab_value[y][x1] > max)
		{
			count++;
			max = tab_value[y][x1];
		}
	}
	if (tab_condition[0][x1] != count)
		return (0);
	return (1);
}

int		ft_check_bottom(int **tab_value, int **tab_condition, int size, int x1)
{
	int y;
	int max;
	int count;

	max = 0;
	count = 0;
	y = size;
	while (--y > -1)
	{
		if (tab_value[y][x1] > max)
		{
			count++;
			max = tab_value[y][x1];
		}
	}
	if (tab_condition[1][x1] != count)
		return (0);
	return (1);
}
