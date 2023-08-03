/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_c_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:50:19 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/28 19:41:21 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

void	task_nullcase(char c, t_csset *csset)
{
	int	i;

	csset->cs = '\0';
	i = 0;
	if (csset->flag.left == 1)
	{
		write(1, &c, 1);
		i++;
		while (i < csset->flag.padding)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i + 1 < csset->flag.padding)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, &c, 1);
	}
}

char	*ft_converter_c(t_csset *csset, va_list *ap)
{
	unsigned char	c;
	char			*str;
	char			*src;

	c = va_arg(*ap, int);
	if (csset->flag.padding == 0)
		csset->flag.padding = 1;
	src = (char *)ft_calloc(2, sizeof(char));
	if (!src)
		return (NULL);
	src[0] = c;
	if (!ft_isprint(c))
	{
		task_nullcase(c, csset);
		src[0] = '\0';
		return (src);
	}
	else
	{
		str = make_str(csset, src, 1, ' ');
		if (!str)
			return free_return(src);
		free(src);
		return (str);
	}
}
