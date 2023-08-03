/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_csset_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:19:22 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/28 19:40:44 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	print_len_check(t_csset *csset, long long len)
{
	long long	len_print;

	len_print = 0;
	len_print += csset->precision.length;
	if (csset->flag.sign || csset->flag.sign_sp)
		len_print += 1;
	if (csset->flag.hash)
		len_print += 2;
	if (csset->flag.padding > (int)len_print)
		len_print = csset->flag.padding;
	if (len_print + len > INT_MAX - 1)
		return (1);
	else
		return (0);
}

int	comb_flag_check(t_csset *csset)
{
	if (csset->flag.sign && csset->flag.sign_sp)
		return (0);
	return (1);
}

int	oder_flag_check(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '0'
			|| str[i] == '#' || str[i] == ' ' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if ((str[i] == '.' && str[i + 1] == '.'))
			break ;
		else if (str[i] == '.')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (is_cs(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	allowed_flag_check(t_csset *csset)
{
	if (csset->cs == 'c')
		if (csset->flag.zero || csset->flag.hash
			|| csset->flag.sign_sp || csset->flag.sign)
			return (0);
	if (csset->cs == 's')
		if (csset->flag.zero || csset->flag.hash
			|| csset->flag.sign || csset->flag.sign_sp)
			return (0);
	if (csset->cs == 'd' || csset->cs == 'i')
		if (csset->flag.hash)
			return (0);
	if (csset->cs == 'u')
		if (csset->flag.sign || csset->flag.hash || csset->flag.sign_sp)
			return (0);
	if (csset->cs == 'x' || csset->cs == 'X')
		if (csset->flag.sign || csset->flag.sign_sp)
			return (0);
	return (1);
}

int	ft_check_csset(t_csset *csset, char *str)
{
	if (oder_flag_check(str))
	{
		if (csset->cs == '%')
			return (0);
		if (allowed_flag_check(csset))
			if (comb_flag_check(csset))
				return (0);
	}
	return (1);
}
