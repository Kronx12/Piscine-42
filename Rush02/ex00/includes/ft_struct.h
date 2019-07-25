/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 14:13:59 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 23:10:37 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include "lib.h"

int				ft_counter(struct s_value *tab);
struct s_value	*ft_structdup(struct s_value *tab, struct s_value *dest);
char			append(char *str, char *add);
struct s_value	*ft_struct(struct s_value *tab, int nbr);
void			ft_aff_struct(struct s_value *tab, char *str, char *strb);

#endif
