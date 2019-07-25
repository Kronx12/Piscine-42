/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 04:29:02 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/15 23:56:20 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_base_len(char *base);
int		ft_pow(int nb, int power);
int		ft_get_value(char *base, char c);

int		ft_atoi(char *nbr, char *base)
{
	int res;
	int i;

	res = 0;
	i = -1;
	if (nbr[0] == '-')
		i++;
	while (nbr[++i])
		res += ft_pow(ft_base_len(base),
				ft_strlen(nbr) - i - 1) * ft_get_value(base, nbr[i]);
	return (nbr[0] == '-') ? res * -1 : res;
}

int		ft_maxpow(int len, int nb)
{
	int max;

	max = 0;
	while (ft_pow(len, max) < nb)
		max++;
	return (max);
}

int		ft_intlen(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmp;
	int		max;
	int		count;
	char	*res;

	if (!(ft_base_len(base_from) || ft_base_len(base_to)))
		return (0);
	tmp = ft_atoi(nbr, base_from);
	res = malloc(sizeof(char) * ft_intlen(tmp));
	count = (tmp < 0) ? 1 : 0;
	res[0] = (tmp < 0) ? '-' : res[0];
	tmp = (tmp < 0) ? tmp * -1 : tmp;
	max = ft_maxpow(ft_base_len(base_to), tmp) - 1;
	while (max > 0)
	{
		res[count] = base_to[tmp / ft_pow(ft_base_len(base_to), max)];
		tmp -= ft_pow(ft_base_len(base_to), max) *
			(tmp / ft_pow(ft_base_len(base_to), max));
		max--;
		count++;
	}
	res[count] = base_to[tmp / ft_pow(ft_base_len(base_to), max)];
	return (res);
}
