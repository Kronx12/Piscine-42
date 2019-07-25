/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rev_int_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 17:47:56 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 20:01:46 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int mid;
	int i;
	int tmp;

	if (size % 2 == 1)
	{
		mid = (size - 1) / 2;
	}
	else
	{
		mid = size / 2;
	}
	size--;
	i = 0;
	while (i < mid)
	{
		tmp = tab[size - i];
		tab[size - i] = tab[i];
		tab[i] = tmp;
		i++;
	}
}
