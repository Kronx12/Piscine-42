/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 15:53:00 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 17:00:15 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (str++[0])
		write(1, str - 1, 1);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	j = 1;
	i = 0;
	while (j)
	{
		j = 0;
		while (i < argc - 1)
		{
			i++;
			while (ft_strcmp(argv[i], argv[i - 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i - 1];
				argv[i - 1] = tmp;
				j = 1;
			}
		}
		i = 0;
	}
	while (argc-- > 1)
		ft_putstr(argv[argc - 1]);
	return (0);
}
