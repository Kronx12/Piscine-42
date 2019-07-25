/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver_1.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 22:28:54 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 22:33:35 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**ft_get_int_tab(char *str)
{
	int **tab;
	int i;

	tab = malloc(sizeof(tab) * 4);
	i = -1;
	while (++i < 4)
		tab[i] = malloc(sizeof(tab) * 4);
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			tab[i / 8][i / 2 % 4] = str[i] - '0';
	return (tab);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	debug_tab_int(int **tab_value)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			ft_putchar(tab_value[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
		}
		write(1, "\n", 1);
		j = -1;
	}
}

int		**place_4(int **tab_value, int *x, int *y, int size)
{
	int tmp;

	if (*y % 2 == 0)
	{
		tmp = -1;
		while (++tmp < size)
		{
			if (*y == 0)
				tab_value[tmp][*x] = tmp + 1;
			else
				tab_value[*x][tmp] = tmp + 1;
		}
	}
	else if (*y % 2 == 1)
	{
		tmp = size;
		while (--tmp > -1)
		{
			if (*y == 1)
				tab_value[tmp][*x] = tmp + 1;
			else
				tab_value[*x][tmp] = tmp + 1;
		}
	}
	return (tab_value);
}

int		**place_base(int **tab_condition, int **tab_value, int size)
{
	int x;
	int y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (tab_condition[y][x] == 1)
			{
				if (y < 2)
					tab_value[(y == 1) ? 3 : 0][x] = 4;
				else
					tab_value[x][(y == 3) ? 3 : 0] = 4;
			}
			else if (tab_condition[y][x] == 4)
			{
				tab_value = place_4(tab_value, &x, &y, size);
			}
		}
	}
	return (tab_value);
}
