/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:20:59 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/27 12:25:43 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	is_cs(char c)
{
	int	i;

	i = 0;
	while (i < CS_MAX)
	{
		if (c == CS[i])
			return (c);
		i++;
	}
	return (0);
}

size_t	ft_lencsset(const char *str)
{
	int	i;

	i = 1;
	while (!is_cs(str[i]) && str[i])
		i++;
	if (is_cs(str[i]))
		i++;
	return (i);
}

void	init_csset(t_csset *csset)
{
	csset->flag.left = 0;
	csset->flag.sign = 0;
	csset->flag.sign_sp = 0;
	csset->flag.hash = 0;
	csset->flag.zero = 0;
	csset->flag.padding = 0;
	csset->precision.dot = 0;
	csset->precision.length = 0;
	csset->cs = 0;
}

void	set_converter(char *(**converter)(t_csset *, va_list *))
{
	converter[0] = &ft_converter_c;
	converter[1] = &ft_converter_s;
	converter[2] = &ft_converter_p;
	converter[3] = &ft_converter_d;
	converter[4] = &ft_converter_i;
	converter[5] = &ft_converter_u;
	converter[6] = &ft_converter_x;
	converter[7] = &ft_converter_upx;
	converter[8] = &ft_converter_per;
}
