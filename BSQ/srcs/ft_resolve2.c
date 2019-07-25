/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 10:40:43 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 22:16:43 by jedelfos    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lib.h"

unsigned long	get_h(char *grid)
{
	unsigned long	height;
	int				i;

	i = 0;
	height = 0;
	while (grid[i] <= '9' && grid[i] >= '0')
	{
		height = height + (grid[i] - '0');
		height = height * 10;
		i++;
	}
	if (height > 500000000)
		return (0);
	return ((height / 10) + 1);
}

unsigned long	get_w(char *grid)
{
	unsigned long	width;
	int				i;

	width = 0;
	i = 0;
	while (grid[i] != '\n')
		i++;
	i++;
	while (grid[width + i] != '\n')
		width++;
	return (width);
}

t_point			ft_write_grid(t_point var)
{
	var.i = 0;
	if (var.result_value == -1)
		return (var);
	while (var.j <= var.result_value)
	{
		var.i = 0;
		while (var.i <= (unsigned long long)var.result_value)
			var.result_pose[(var.i++ * -1) - (var.j * (var.width + 1))] =
				var.square_value;
		var.j++;
	}
	return (var);
}

t_point			char_value_calculation(char *grid, t_point var)
{
	int		i;

	i = 0;
	while (grid[i] <= '9' && grid[i] >= '0')
		i++;
	var.void_value = grid[i];
	var.wall_value = grid[i + 1];
	var.square_value = grid[i + 2];
	return (var);
}

char			chek_first_line(char *grid)
{
	int i;

	i = 0;
	while (grid[i] <= '9' && grid[i] >= '0')
		i++;
	if (grid[i] == '\n' || grid[i + 1] == '\n' || grid[i + 2] == '\n')
		return (0);
	if (grid[i + 3] != '\n')
		return (0);
	if (grid[i] == grid[i + 1] || grid[i] == grid[i + 2]
			|| grid[i + 1] == grid[i + 2])
		return (0);
	return (1);
}
