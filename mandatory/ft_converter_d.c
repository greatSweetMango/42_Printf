/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:25:53 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/27 12:19:16 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_converter_d(t_csset *csset, va_list *ap)
{
	char	*str;
	char	*src;
	int		num;
	int		len_num;
	int		sign;

	num = va_arg(*ap, int);
	src = ft_itoa(num);
	sign = get_sign(src);
	len_num = ft_strlen(src);
	if (precision_zero(csset, src, sign))
		src = make_precision_str(csset, src, sign, len_num);
	if (!src)
		return (NULL);
	if (csset->flag.zero && !csset->precision.dot)
		str = make_str(csset, src, ft_strlen(src), '0');
	else
		str = make_str(csset, src, ft_strlen(src), ' ');
	if (!str)
		return free_return(src);
	put_sign(csset, str, sign, src);
	if (src)
		free(src);
	return (str);
}
