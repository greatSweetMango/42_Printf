/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:24:42 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/27 06:24:44 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_converter_per(t_csset *csset, va_list *ap)
{
	char	*src;
	char	*str;

	(void)ap;
	src = (char *)ft_calloc(2, sizeof(char));
	src[0] = '%';
	str = make_str(csset, src, 1, ' ');
	if (!str)
		return free_return(src);
	if (src)
		free(src);
	return (str);
}
