/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 16:38:50 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 16:53:33 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check_base(char *base)
{
	int i;
	int j;
	char compare[] = {'+', '-', ' ', '\r', '\f', '\v', '\n', '\t'};
	
	i = 0;
	while(base[i])
	{
		j = 0;
		while(compare[j])
		{
			if (base[i] == compare[j])
				return (0);
			j++;
		}
		j = 0;
		while(base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_get_value(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int base_len;
	int val;
	int val_len;

	i = 0;
	val = 0;
	val_len = ft_strlen(str);
	base_len = ft_check_base(base);	
	if (base_len > 0)
	{
		while (str[i])
		{
			val += (base_len * ft_get_value(base, str[i]));
			i++;
		}
		return (val);
	}
	else
		return (0);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("123", "0123456789"));
	ft_atoi_base("ff", "0123456789abcdef");
	ft_atoi_base("ff", "0123456\t789abcdef");
	ft_atoi_base("ff", "0123456+789abcdef");
	return (0);
}
