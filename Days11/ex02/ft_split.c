/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 01:52:28 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 13:48:17 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_in_charset(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int i, int len)
{
	char	*strr;
	int		k;

	k = 0;
	strr = malloc(sizeof(*str) * (len + 1));
	while (k < len)
	{
		strr[k] = str[i + k];
		k++;
	}
	strr[k] = '\0';
	return (strr);
}

int		ft_getcount(char *str, char *charset)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (str[++i])
		if (!(ft_is_in_charset(str[i], charset)) && count++)
			while (str[i] && !(ft_is_in_charset(str[i], charset)))
				i++;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		count;
	int		start;

	if (!(tab = malloc(sizeof(*tab) * ft_getcount(str, charset))))
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (!(ft_is_in_charset(str[i], charset)))
		{
			start = i;
			while (str[i] && !(ft_is_in_charset(str[i], charset)))
				i++;
			tab[count] = ft_strdup(str, start, i - start);
			count++;
		}
		i++;
	}
	tab[count] = 0;
	return (tab);
}
