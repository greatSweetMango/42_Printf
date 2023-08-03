/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:27:58 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/25 20:28:00 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_converter_s(t_csset *csset, va_list *ap)
{
	char	*src;
	char	*str;
	size_t	len_src;

	src = va_arg(*ap, char *);
	if (src == NULL)
		len_src = 6;
	else
		len_src = ft_strlen(src);
	if (csset->precision.dot == 1 && len_src > (size_t)csset->precision.length)
		len_src = csset->precision.length;
	if (src == NULL)
		str = make_str(csset, "(null)", len_src, ' ');
	else
		str = make_str(csset, src, len_src, ' ');
	if (!str)
		return free_return(src);
	return (str);
}
