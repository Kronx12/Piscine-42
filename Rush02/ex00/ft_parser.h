/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 14:19:15 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 14:22:43 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

char			*get_dict(char *file);
struct s_value	*transform_dict_tab_to_struct(char *val);

#endif
