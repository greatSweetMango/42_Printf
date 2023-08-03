/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_p_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:46:51 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/26 00:46:53 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	ft_hex_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

char	*ft_hex_to_str(unsigned long long ptr, int len_ptr)
{
	int		i;
	char	*str;

	str = (char *)ft_calloc(len_ptr + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = len_ptr - 1;
	while (i > 1)
	{
		str[i] = ptr % 16;
		if (str[i] < 10)
			str[i] += '0';
		else
			str[i] = str[i] - 10 + 'a';
		ptr /= 16;
		i--;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*ft_converter_p(t_csset *csset, va_list *ap)
{
	char				*hex_str;
	char				*str;
	unsigned long long	ptr;
	int					len_ptr;

	ptr = va_arg(*ap, unsigned long long);
	if (ptr == 0)
		len_ptr = 3;
	else
		len_ptr = ft_hex_len(ptr) + 2;
	hex_str = ft_hex_to_str(ptr, len_ptr);
	if (!hex_str)
		return (NULL);
	str = make_str(csset, hex_str, len_ptr, ' ');
	if (!str)
		return free_return(hex_str);
	if (hex_str)
		free(hex_str);
	return (str);
}
