/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 06:16:33 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 01:41:58 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		count(char **strs, int size, int sepl)
{
	int count;

	count = 0;
	while (size--)
		count += ft_strlen(strs[size]) + sepl;
	return (count);
}

char	*check(int size, char *str, int j)
{
	if (size != 0)
		str[j] = '\0';
	if (size == 0)
		if (!(str = malloc(sizeof(str) * 1)))
			return (NULL);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*tmp;
	int		c;
	int		i;
	int		j;

	j = (size == 0) ? 1 : count(strs, size, ft_strlen(sep)) - ft_strlen(sep);
	if (!(str = malloc(sizeof(*str) * j)))
		return (NULL);
	i = -1;
	c = 0;
	while (++i < size)
	{
		tmp = strs[i];
		while (tmp++[0])
			str[c++] = tmp[-1];
		if (i != size - 1)
		{
			tmp = &sep[0];
			while (tmp++[0])
				str[c++] = tmp[-1];
		}
	}
	return (check(size, str, j));
}
