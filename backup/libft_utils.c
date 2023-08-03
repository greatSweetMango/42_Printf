/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:46:10 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/22 21:46:11 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s++)
	{
		cnt++;
	}
	return (cnt);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rv;
	unsigned int	i;

	if (count != 0 && size != 0)
		if (count / size > UINT_MAX / size || size / count > UINT_MAX / size)
			return (NULL);
	rv = (unsigned char *)malloc(count * size);
	if (!rv)
		return (NULL);
	i = 0;
	while (i < count * size)
		rv[i++] = 0;
	return (rv);
}

size_t	ft_strlcpy(char *dst,
						const char *src,
						size_t dstsize)
{
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	len_src = i;
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (len_src);
}

int	ft_atoi(const char *str)
{
	int	rv;
	int	sign;

	rv = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		rv *= 10;
		rv += (*str - '0') * sign;
		str++;
	}
	return (rv);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	char			*rv;
	unsigned int	i;

	i = 0;
	while (s1[i])
		i++;
	rv = (char *)malloc(i * sizeof(char) + 1);
	if (!rv)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		rv[i] = s1[i];
		i++;
	}
	rv[i] = '\0';
	return (rv);
}

static size_t	len_num(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*rv;
	long long	num;
	int			i;
	int			neg;

	neg = 1;
	rv = (char *)malloc(len_num(n) * sizeof(char) + 1);
	if (!rv)
		return (NULL);
	num = n;
	if (n < 0)
	{
		neg = 0;
		rv[0] = '-';
		num *= -1;
	}
	i = 0;
	while (i < (int)len_num(n) + neg - 1)
	{
		rv[len_num(n) - i - 1] = num % 10 + '0';
		num /= 10;
		i++;
	}
	rv [len_num(n)] = 0;
	return (rv);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}