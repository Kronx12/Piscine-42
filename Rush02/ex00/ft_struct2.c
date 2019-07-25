/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 23:02:40 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 23:12:39 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"
#include "ft_struct.h"

void	ft_tmp(struct s_value *tab, char *strb,
		struct s_value *tmp, int *int_tab)
{
	while (int_tab[0] != 0 && int_tab[0]--)
	{
		if (tab[int_tab[0]].count > 20)
		{
			tmp = ft_struct(tmp, tab[int_tab[0]].count);
			int_tab[1] = ft_counter(tmp) + 1;
			while (int_tab[1] != 0 && int_tab[1]--)
				if (tmp[int_tab[1]].count != 0)
				{
					if (tmp[int_tab[1]].val >= 100)
						append(strb, tmp[tmp[int_tab[1]].count].str);
					append(strb, tmp[int_tab[1]].str);
					tmp[int_tab[1]].count = 0;
				}
			append(strb, tab[int_tab[0]].str);
		}
		else if (tab[int_tab[0]].count != 0)
		{
			if (tab[int_tab[0]].val >= 100)
				append(strb, tab[tab[int_tab[0]].count].str);
			append(strb, tab[int_tab[0]].str);
			tab[int_tab[0]].count = 0;
		}
	}
}
