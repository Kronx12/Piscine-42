/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 01:34:03 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 01:04:42 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *ptr;

	if (min >= max)
		return (NULL);
	else
	{
		ptr = malloc(sizeof(int) * (max - min));
		i = -1;
		while (min + (++i) < max)
			ptr[i] = min + i;
		return (ptr);
	}
}
