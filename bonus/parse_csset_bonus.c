/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_csset_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:46:44 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/22 23:46:48 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

void	catch_flag( t_csset *csset, char c)
{
	if (c == '-')
		csset->flag.left = 1;
	else if (c == '+')
		csset->flag.sign = 1;
	else if (c == ' ')
		csset->flag.sign_sp = 1;
	else if (c == '#')
		csset->flag.hash = 1;
}

int	get_flag(t_csset *csset, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.' && !is_cs(str[i]))
	{
		if (str[i] > '0' && str[i] <= '9')
			break ;
		if (str[i] == '0')
		{
			csset->flag.zero = 1;
			while (str[i] != '0')
				i++;
		}
		catch_flag(csset, str[i]);
		i++;
	}
	return (i);
}

void	parse_csset(t_csset *csset, char *str)
{
	str++;
	str += get_flag(csset, str);
	csset->flag.padding = ft_atoi(str);
	while (*str != '.' && !is_cs(*str))
		str++;
	if (*str == '.')
	{
		csset->precision.dot = 1;
		str++;
		csset->precision.length = ft_atoi(str);
		while (!is_cs(*str))
			str++;
	}
	csset->cs = *str;
}
