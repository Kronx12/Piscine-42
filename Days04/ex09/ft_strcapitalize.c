/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 16:51:31 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 04:14:22 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int b;

	i = -1;
	b = 1;
	ft_strlowcase(str);
	while (str[++i] != '\0')
	{
		if ((str[i] < 97 || str[i] > 122) && (str[i] > 90
					|| str[i] < 65) && (str[i] > 57 || str[i] < 48))
			b = 1;
		else
		{
			if (b && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			b = 0;
		}
	}
	return (str);
}
