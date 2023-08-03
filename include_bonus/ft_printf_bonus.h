/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:55:54 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/28 19:42:42 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define CS "cspdiuxX%"
# define CS_MAX 9

typedef struct s_flag
{
	int	left;
	int	sign;
	int	sign_sp;
	int	hash;
	int	zero;
	int	padding;
}	t_flag;

typedef struct s_precision
{
	int	dot;
	int	length;
}	t_precision;

typedef struct s_csset
{
	t_flag		flag;
	t_precision	precision;
	char		cs;
}	t_csset;

int		ft_printf(const char *str, ...);
int		task_print(const char *str,
			va_list *ap, t_csset *csset,
			long long *len);
int		print_csset2str(t_csset *csset, va_list *ap, long long *len);
int		get_csset(t_csset *csset, const char *str);
int		check_param(t_csset *csset, const char *str, va_list srcap, int flag);

void	parse_csset(t_csset *csset, char *str);
int		get_flag(t_csset *csset, char *str);
void	catch_flag( t_csset *csset, char c);

void	set_converter(char *(**converter)(t_csset *, va_list *));
void	init_csset(t_csset *csset);
size_t	ft_lencsset(const char *str);
int		is_cs(char c);

char	*ft_hex_to_str(unsigned long long ptr, int len_ptr);
int		ft_hex_len(unsigned long long ptr);
char	*ft_uitoa(unsigned int n);
size_t	len_uint(unsigned int n);
char	*ft_itohex_str(unsigned int num);
int		ft_uihex_len(unsigned int hex);

void	task_nullcase(char c, t_csset *csset);
char	*make_precision_str(t_csset *csset,
			char *src, int sign,
			size_t len_src);
void	put_sign(t_csset *csset, char *str, int sign, char *src);
int		precision_zero(t_csset *csset, char *src, int sign);
int		get_sign(char *str);
char	*make_precision_str_hex(t_csset *csset, char *src, size_t len_src);
void	put_hash(t_csset *csset, char *str, char *src);
int		precision_zero_hex(t_csset *csset, char *src);
char	*make_str(t_csset *csset, char *src, size_t len_src, char c);
char	*free_return(char *src);
void	set_converter(char *(**converter)(t_csset *, va_list *));
void	init_csset(t_csset *csset);
size_t	ft_lencsset(const char *str);
int		is_cs(char c);

char	*ft_converter_c(t_csset *csset, va_list *ap);
char	*ft_converter_d(t_csset *csset, va_list *ap);
char	*ft_converter_i(t_csset *csset, va_list *ap);
char	*ft_converter_c(t_csset *csset, va_list *ap);
char	*ft_converter_s(t_csset *csset, va_list *ap);
char	*ft_converter_p(t_csset *csset, va_list *ap);
char	*ft_converter_d(t_csset *csset, va_list *ap);
char	*ft_converter_i(t_csset *csset, va_list *ap);
char	*ft_converter_u(t_csset *csset, va_list *ap);
char	*ft_converter_x(t_csset *csset, va_list *ap);
char	*ft_converter_upx(t_csset *csset, va_list *ap);
char	*ft_converter_per(t_csset *csset, va_list *ap);

int		ft_check_csset(t_csset *csset, char *str);
int		allowed_flag_check(t_csset *csset);
int		oder_flag_check(char *str);
int		comb_flag_check(t_csset *csset);
int		print_len_check(t_csset *csset, long long len);

#endif
