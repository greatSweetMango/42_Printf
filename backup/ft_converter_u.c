/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:54:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/27 12:21:10 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	len_uint(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_uitoa(unsigned int n)
{
	char		*rv;
	int			i;
	int			len_num;

	rv = (char *)malloc(len_uint(n) * sizeof(char) + 1);
	if (!rv)
		return (NULL);
	len_num = len_uint(n);
	i = len_num - 1;
	while (i >= 0)
	{
		rv[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	rv [len_num] = '\0';
	return (rv);
}

char	*ft_converter_u(t_csset *csset, va_list *ap)
{
	char			*str;
	char			*src;
	int				len_num;
	int				sign;

	src = ft_uitoa(va_arg(*ap, unsigned int));
	if (!src)
		return (NULL);
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
