/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: julicler <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 12:13:33 by julicler     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 23:14:09 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>
#include "ft_struct2.h"

int				ft_counter(struct s_value *tab)
{
	int i;

	i = 0;
	while (tab[i].str)
		i++;
	return (i - 1);
}

struct s_value	*ft_structdup(struct s_value *tab, struct s_value *dest)
{
	int i;

	i = -1;
	while (tab[++i].str != 0)
		;
	dest = malloc(sizeof(struct s_value) * (i + 1));
	i = -1;
	while (tab[++i].str != 0)
	{
		dest[i].val = tab[i].val;
		dest[i].count = 0;
		dest[i].str = ft_strdup(tab[i].str);
	}
	dest[i].str = 0;
	return (dest);
}

char			*append(char *str, char *add)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (str[i])
		i++;
	while (add[k])
	{
		str[i + k] = add[k];
		k++;
	}
	str[i + k] = ' ';
	return (str);
}

struct s_value	*ft_struct(struct s_value *tab, int nbr)
{
	int		i;
	int		j;
	int		k;

	j = ft_counter(tab);
	i = -1;
	if (nbr < 0 && (nbr *= -1))
		write(1, "-", 1);
	while (tab[++i].str != 0)
		if (tab[i].count)
			tab[i].count = 0;
	if (nbr == 0 && (k = -1))
	{
		while (tab[0].str[++k])
			write(1, &tab[0].str[k], 1);
		return (0);
	}
	else if (j++)
	{
		while (j != 0 && nbr > 0 && j--)
			while (nbr - tab[j].val >= 0 && (tab[j].count += 1))
				nbr -= tab[j].val;
	}
	return (tab);
}

void			ft_aff_struct(struct s_value *tab, char *str, char *strb)
{
	int				count;
	int				*int_tab;
	int				k;
	struct s_value	*tmp;

	if (!(int_tab = malloc(sizeof(int) * 2)))
		return ;
	tmp = ft_structdup(tab, tmp);
	if(!(tab = ft_struct(tab, ft_atoi(str))))
		return ;
	int_tab[0] = ft_counter(tab) + 1;
	int_tab[1] = tab[int_tab[0]].count;
	ft_tmp(tab, strb, tmp, int_tab);
	while (strb++[1])
		write(1, &strb[-1], 1);
}
