/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:53:33 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/22 17:53:36 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check_param(t_csset *csset, const char *str, va_list srcap, int flag)
{
	va_list	ap;
	char	*csset_str;
	size_t	len_csset;

	va_copy(ap, srcap);
	while (*str)
	{
		if (*str == '%')
		{
			len_csset = get_csset(csset, str);
			csset_str = (char *)ft_calloc(len_csset + 1, sizeof(char));
			if (!csset_str || !len_csset)
				return (1);
			ft_strlcpy(csset_str, str, len_csset + 1);
			str += len_csset;
			if (ft_check_csset(csset, csset_str))
				flag = 1;
			if (csset_str)
				free(csset_str);
		}
		else
			str++;
	}
	va_end(ap);
	return (flag);
}

int	get_csset(t_csset *csset, const char *str)
{
	char	*csset_str;
	size_t	len_csset;

	init_csset(csset);
	len_csset = ft_lencsset(str);
	csset_str = (char *)ft_calloc(len_csset + 1, sizeof(char));
	if (!csset_str)
		return (0);
	ft_strlcpy(csset_str, str, len_csset + 1);
	parse_csset(csset, csset_str);
	if (csset_str)
		free(csset_str);
	return (len_csset);
}

int	print_csset2str(t_csset *csset, va_list *ap, long long *len)
{
	char		*str;
	char		*(*converter[9])(t_csset *, va_list *);
	int			i;

	set_converter(converter);
	i = -1;
	while (++i < CS_MAX)
	{
		if (CS[i] == csset->cs)
			break ;
	}
	str = converter[i](csset, ap);
	if (!str)
		return (1);
	if (csset->cs == '\0')
		len[0] += csset->flag.padding;
	else
		len[0] += ft_strlen(str);
	if (*len < (long long)INT_MAX)
		ft_putstr_fd(str, 1);
	if (str)
		free(str);
	return (0);
}

int	task_print(const char *str, va_list *ap, t_csset *csset, long long *len)
{
	int	len_csset;

	len_csset = 0;
	if (*str == '%')
	{
		len_csset = get_csset(csset, str);
		if (len_csset == -1)
			return (0);
		if (print_len_check(csset, *len))
		{
			len[0] = INT_MAX;
			return (len_csset);
		}
		if (print_csset2str(csset, ap, len))
			return (0);
	}
	else
	{
		(*len)++;
		if (*len < INT_MAX)
			write(1, str, 1);
		return (1);
	}
	return (len_csset);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_csset		csset;
	int			print_len;
	long long	len;

	va_start(ap, str);
	if (check_param(&csset, str, ap, 0))
		return (-1);
	len = 0;
	while (*str)
	{
		print_len = task_print(str, &ap, &csset, &len);
		str += print_len;
		if (len > INT_MAX - 1 || !print_len)
			return (-1);
	}
	va_end(ap);
	return (len);
}
