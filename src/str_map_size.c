/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:47:47 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 17:59:36 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static void			del_two_str(char **str1, char **str2)
{
	ft_memdel((void **)str1);
	ft_memdel((void **)str2);
}

char				*get_str_map_size(int w, int h)
{
	char			*result;
	char			*str_w;
	char			*str_h;

	str_w = ft_itoa(w);
	if (str_w == NULL)
		return (false);
	str_h = ft_itoa(h);
	if (str_h == NULL)
	{
		del_two_str(&str_w, &str_h);
		return (false);
	}
	result = ft_strnew(8 + ft_strlen(str_h) + ft_strlen(str_w));
	if (result == NULL)
	{
		ft_memdel((void **)&str_h);
		return (false);
	}
	ft_strcat(result, "map: ");
	ft_strcat(result, str_h);
	ft_strcat(result, " x ");
	ft_strcat(result, str_w);
	del_two_str(&str_w, &str_h);
	return (result);
}
