/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils_xX_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 03:44:15 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/27 03:44:16 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	precision_zero_hex(t_csset *csset, char *src)
{
	if (src[0] == '0')
	{
		csset->flag.hash = 0;
		if (!csset->precision.length && csset->precision.dot)
		{
			src[0] = '\0';
			return (0);
		}
	}
	return (1);
}

void	put_hash(t_csset *csset, char *str, char *src)
{
	int	index;
	int	len_num;

	len_num = ft_strlen(src) - 1;
	if (csset->flag.hash == 0)
		return ;
	if ((csset->flag.zero && !csset->precision.dot) || csset->flag.left)
		index = 0;
	else if (len_num >= csset->precision.length)
		index = ft_strlen(str) - len_num - 1;
	else
		index = ft_strlen(str) - csset->precision.length - 1;
	str[index] = '0';
	str[index + 1] = 'x';
}

char	*make_precision_str_hex(t_csset *csset, char *src, size_t len_src)
{
	char	*str;
	char	hash_sp;
	int		i;

	hash_sp = 0;
	if (csset->flag.hash)
		hash_sp = 2;
	if (len_src >= (size_t)csset->precision.length)
	{
		str = (char *)ft_calloc(len_src + hash_sp + 1, sizeof(char));
		csset->precision.length = len_src;
	}
	else
		str = (char *)ft_calloc(csset->precision.length + hash_sp + 1,
				sizeof(char));
	if (!str)
		return (free_return(src));
	i = 0;
	while (i < csset->precision.length + hash_sp - (int)len_src)
		str[i++] = '0';
	ft_strlcpy(str + i, src, len_src + 1);
	if (src)
		free(src);
	return (str);
}
