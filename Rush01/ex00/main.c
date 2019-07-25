/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 05:40:21 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 22:44:42 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**ft_get_int_tab(char *str);
void	ft_putchar(char c);
void	debug_tab_int(int **tab_value);
int		**place_4(int **tab_value, int *x, int *y, int size);
int		**place_base(int **tab_condition, int **tab_value, int size);
int		check_diff_vert(int **tab, int size);
int		check_diff_hort(int **tab, int size);
int		check_diff(int **tab, int size);
int		ft_check_top(int **tab_value, int **tab_condition, int size, int x1);
int		ft_check_bottom(int **tab_value, int **tab_condition, int size, int x1);
int		ft_check_left(int **tab_value, int **tab_condition, int size, int y1);
int		ft_check_right(int **tab_value, int **tab_condition, int size, int y1);
int		ft_check_global(int **tab_value, int **tab_condition, int size);
int		tab_increment_2(int **tab_value, int *x, int *y, int **tab_mask);
void	tab_increment(int **tab_value, int **tab_mask,
		int **tab_cond, int size);
int		**get_value_tab(int size);
int		**ft_made_mask(int **tab_value, int size);
int		arg_is_valid(char *str);

int		main(int argc, char **argv)
{
	int		size;
	int		**tab_cond;
	int		**tab_value;
	int		**tab_mask;

	size = 4;
	if (argc == 2 && arg_is_valid(argv[1]))
	{
		tab_cond = ft_get_int_tab(argv[1]);
		tab_value = get_value_tab(size);
		tab_mask = ft_made_mask(place_base(tab_cond, tab_value, size), size);
		tab_increment(tab_value, tab_mask, tab_cond, size);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
