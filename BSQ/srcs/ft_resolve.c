/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jedelfos <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 10:51:15 by jedelfos     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 22:18:31 by jedelfos    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lib.h"

t_point			var_init(char *grid, t_point var)
{
	var.grid = grid;
	var.u = 0;
	var.i = 0;
	var.j = 0;
	var.check_height = 0;
	var.result_value = -1;
	var.first_line = 1;
	if (!(var.last_grid_result = malloc(sizeof(int) * (var.width + 1))))
		var.first_line = 0;
	if (!(var.grid_result = malloc(sizeof(int) * (var.width + 1))))
		var.first_line = 0;
	while (var.grid[0] != '\n')
		var.grid++;
	var.grid++;
	return (var);
}

t_point			ft_resolve_4(t_point var)
{
	if ((var.grid[0] == var.void_value && var.first_line == 1) ||
			(var.grid[-1] == '\n' && var.grid[0] == var.void_value))
	{
		var.grid_result[var.i] = 0;
		if (var.grid_result[var.i] > var.result_value)
		{
			var.result_value = var.grid_result[var.i];
			var.result_pose = &var.grid[0];
		}
	}
	else if (var.grid[0] == var.void_value && var.first_line == 0)
	{
		var.grid_result[var.i] = var.grid_result[var.i - 1] + 1;
		if (var.last_grid_result[var.i - 1] < var.grid_result[var.i] - 1)
			var.grid_result[var.i] = var.last_grid_result[var.i - 1] + 1;
		if (var.last_grid_result[var.i] < var.grid_result[var.i] - 1)
			var.grid_result[var.i] = var.last_grid_result[var.i] + 1;
		if (var.grid_result[var.i] > var.result_value)
		{
			var.result_value = var.grid_result[var.i];
			var.result_pose = &var.grid[0];
		}
	}
	return (var);
}

t_point			ft_resolve_2(t_point var)
{
	if (var.grid[0] == '\n')
	{
		var.grid_result[var.i] = -1;
		var.first_line = 0;
	}
	if (var.grid[0] == var.wall_value)
		var.grid_result[var.i] = -1;
	var = ft_resolve_4(var);
	return (var);
}

t_point			ft_resolve_3(t_point var)
{
	var.i++;
	var.grid++;
	if (var.i > var.width)
	{
		var.check_height++;
		if (var.check_height + 1 == var.height && var.grid[0] != '\0')
			var.square_value = '\n';
		if (var.grid[-1] != '\n')
			var.square_value = '\n';
		var.u = 0;
		while (var.u < var.width + 1)
		{
			var.last_grid_result[var.u] = var.grid_result[var.u];
			var.u++;
		}
		var.last_grid_result[var.u] = -1;
		var.i = 0;
	}
	else if (var.grid[-1] != var.wall_value
			&& var.grid[-1] != var.void_value)
		var.square_value = '\n';
	return (var);
}

char			*ft_resolve(char *grid)
{
	t_point var;

	var.width = get_w(grid);
	var.height = get_h(grid);
	if (chek_first_line(grid) == 0)
		return (0);
	var = char_value_calculation(grid, var);
	var = var_init(grid, var);
	if (var.first_line == 0)
		return (0);
	while (var.grid[0] != '\0')
	{
		var = ft_resolve_2(var);
		var = ft_resolve_3(var);
		if (var.square_value == '\n')
			return (0);
	}
	if (var.check_height != var.height - 1)
		return (0);
	free(var.grid_result);
	free(var.last_grid_result);
	var = ft_write_grid(var);
	if (var.void_value == '\n')
		return (0);
	return (var.grid);
}
