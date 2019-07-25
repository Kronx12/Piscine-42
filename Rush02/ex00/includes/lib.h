/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 22:07:53 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 19:20:24 by julicler    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>

typedef struct	s_value
{
	int		val;
	int		count;
	char	*str;
}				t_value;

int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);

#endif
