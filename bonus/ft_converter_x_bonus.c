/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_x_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:21:44 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/27 12:24:56 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	ft_uihex_len(unsigned int hex)
{
	int	len;

	len = 0;
	if (!hex)
		return (1);
	while (hex)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

char	*ft_itohex_str(unsigned int num)
{
	int		i;
	int		len_hex;
	char	*str;

	len_hex = ft_uihex_len(num);
	str = (char *)ft_calloc(len_hex + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = len_hex - 1;
	while (i >= 0)
	{
		str[i] = num % 16;
		if (str[i] < 10)
			str[i] += '0';
		else
			str[i] = str[i] - 10 + 'a';
		num /= 16;
		i--;
	}
	return (str);
}

char	*ft_converter_x(t_csset *csset, va_list *ap)
{
	char			*str;
	char			*src;
	unsigned int	num;
	int				len_hex;

	num = va_arg(*ap, unsigned int);
	len_hex = ft_uihex_len(num);
	src = ft_itohex_str(num);
	if (!src)
		return (NULL);
	if (precision_zero_hex(csset, src))
		src = make_precision_str_hex(csset, src, len_hex);
	if (!src)
		return (NULL);
	if (csset->flag.zero && !csset->precision.dot)
		str = make_str(csset, src, ft_strlen(src), '0');
	else
		str = make_str(csset, src, ft_strlen(src), ' ');
	if (!str)
		return (NULL);
	put_hash(csset, str, src);
	if (src)
		free(src);
	return (str);
}
