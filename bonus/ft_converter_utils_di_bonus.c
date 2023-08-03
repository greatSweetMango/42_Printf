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

int	get_sign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
		return (-1);
	}
	else
		return (1);
}

int	precision_zero(t_csset *csset, char *src, int sign)
{
	if (src[0] == '0' && csset->precision.length == 0 && csset->precision.dot)
	{
		src[0] = '\0';
		if ((sign < 0 || csset->flag.sign
				|| csset->flag.sign_sp) && !csset->flag.padding)
			csset->flag.padding = 1;
		return (0);
	}
	else
		return (1);
}

void	put_sign(t_csset *csset, char *str, int sign, char *src)
{
	int	index;
	int	len_num;

	len_num = ft_strlen(src) - 1;
	if (src[0] == '0' && csset->precision.length == 0)
		index = ft_strlen(str) - 1;
	else if ((csset->flag.zero && !csset->precision.dot) || csset->flag.left)
		index = 0;
	else if (len_num >= csset->precision.length)
		index = ft_strlen(str) - len_num - 1;
	else
		index = ft_strlen(str) - csset->precision.length - 1;
	if (csset->flag.sign && sign > 0)
		str[index] = '+';
	else if (sign < 0)
		str[index] = '-';
	else if (csset->flag.sign_sp && sign > 0)
		str[index] = ' ';
}

char	*make_precision_str(t_csset *csset, char *src, int sign, size_t len_src)
{
	char			*str;
	int				sign_flag;
	int				i;

	if (csset->precision.length == 0)
		csset->precision.length = 1;
	sign_flag = 1;
	i = 0;
	if (sign > 0 && !csset->flag.sign && !csset->flag.sign_sp)
		sign_flag = 0;
	if (len_src >= (size_t)csset->precision.length)
	{
		str = (char *)ft_calloc(len_src + sign_flag + 1, sizeof(char));
		csset->precision.length = len_src;
	}
	else
		str = (char *)ft_calloc(csset->precision.length + sign_flag + 1,
				sizeof(char));
	if (!str)
		return free_return(src);
	while (i < csset->precision.length + sign_flag - (int)len_src)
		str[i++] = '0';
	ft_strlcpy(str + i, src, len_src + 1);
	free(src);
	return (str);
}
