/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:26:17 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/07 23:33:45 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "../libft.h"

typedef struct	s_flags
{
	int			h;
	int			l;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			length;
	int			percent;
	int			steps;
	int			dash;
	int			float_sign;
	int			precision_sign;
	int			no_string;
	char		type;
	char		dash_sign;
	char		space_or_zero;
}				t_flags;

// int				ft_printf(char *format, ...);
void			type_c(t_flags *flags);
char			*type_di(char *str, t_flags *flags, va_list *ap);
t_flags			flags_analizer(char *str);
void			flags_filler(char *str, t_flags *flags);
char			type_rec(char *str);
int				ft_get_width(char *str);
int				precision_string_val(char *str);
char			*ft_itoa_base_long(size_t nbr, int base, char flag);
char			*ft_itoa_base(unsigned int nbr, int base, char flag);
char			*ft_itoa_long(intmax_t n);
char			*ft_ftoa(double m, t_flags *flags);
int				aprox(char *float_num, double num, t_flags flags);
char			*right_float_part(double float_num,
				char *right_part, int precision);
char			*flags_check_1(t_flags *flags, va_list *ap);
char			*flags_check_2(t_flags *flags, va_list *ap);
char			*flags_check_3(t_flags *flags, va_list *ap);
char			*flags_check_4(t_flags *flags, va_list *ap);
char			*flags_factory(char *str, t_flags *flags);
char			*flags_assign(t_flags *flags, va_list *ap);
char			*flags_easy(char *str, t_flags *flags);
char			*flags_normal(char *str, t_flags *flags);
char			*flags_hard(char *str, t_flags flags);
char			*flags_nightmare(char *str, t_flags *flags);
char			*ft_sign_swap(char *str, t_flags flags);
char			*ft_x_swap(char *str, t_flags flags);
char			*add_digit_precision(char *str, int precision,
				t_flags flags);
char			*get_space_or_zero(char *str, t_flags *flags);
char			*f_minus(char *str, t_flags flags);
char			*f_float_sign(char *str, t_list flags);
char			*f_char_add(char *str, char c);
char			*ft_addchar(char *str, t_flags flags);
char			*ft_cut_string(char *str, int number);
char			*ft_unsign(char *s);
char			*ft_itoa_size_t(size_t n);
char			*get_unsigned_int(char *str);
int				get_unsigned_size(size_t i);

#endif
