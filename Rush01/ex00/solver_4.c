/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver_4.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 22:34:57 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/15 01:10:10 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		**get_value_tab(int size)
{
	int		**tab_value;
	int		x;
	int		y;

	tab_value = malloc(sizeof(tab_value) * size);
	y = -1;
	while (++y < size)
	{
		tab_value[y] = malloc(sizeof(tab_value) * size);
		x = -1;
		while (++x < size)
			tab_value[y][x] = 0;
	}
	return (tab_value);
}

int		**ft_made_mask(int **tab_value, int size)
{
	int **tab;
	int i;
	int x;
	int y;

	tab = malloc(sizeof(tab) * 4);
	i = -1;
	while (++i < size)
		tab[i] = malloc(sizeof(tab) * 4);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			tab[y][x] = (tab_value[y][x] == 0) ? 0 : 1;
	}
	return (tab);
}

int		arg_is_valid(char *str)
{
	int i;
	int len;

	len = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		len++;
		if ((str[i] <= '0' || str[i] >= '5') && str[i] != ' ')
			return (0);
	}
	if (len != 31)
		return (0);
	return (1);
}
