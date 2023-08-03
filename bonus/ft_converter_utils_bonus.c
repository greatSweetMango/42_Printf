/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:51:20 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/26 01:51:21 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

char	*free_return(char	*src)
{
	if (src)
		free(src);
	return (NULL);
}

char	*make_str(t_csset *csset, char *src, size_t len_src, char c)
{
	char	*str;
	int		i;

	if (len_src >= (size_t)csset->flag.padding)
		str = (char *)ft_calloc(len_src + 1, sizeof(char));
	else
		str = (char *)ft_calloc(csset->flag.padding + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (csset->flag.left == 1)
	{
		ft_strlcpy(str, src, len_src + 1);
		i += len_src;
		while (i < csset->flag.padding)
			str[i++] = c;
	}
	else
	{
		while (i < csset->flag.padding - (int)len_src)
			str[i++] = c;
		ft_strlcpy(str + i, src, len_src + 1);
	}
	return (str);
}
