/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:42:20 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/07 23:34:49 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 20
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Get_Next_Line structure
*/

typedef struct		s_array
{
	int				fd_counter;
	char			*left_over_str;
	struct s_array	*next;
}					t_array;

char				*ft_itoa_long_long(intmax_t n);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
void				*ft_memcpy(void *restrict dst,\
					const void *restrict src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *restrict dst,\
					const void *restrict src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1,\
					const char *restrict s2, size_t n);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *restrict dst,\
					const char *restrict src, size_t dstsize);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,\
					const char *needle, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, int select);
char				*ft_strtrim(char const *s);
size_t				ft_trimlen(const char *s);
char				*ft_malloclen(const char *s);
int					ft_wdcount(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_chcount(char const *s, char c);
char				**ft_sfill(char const *s, char **main_str, \
					int wdcount, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_strldup(void const *s, size_t l);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(char *c1, char *c2);
void				ft_print_hex(int nbr, char flag);

/*
** Get_Next_Line
*/

t_array				*list_create(const int fd);
int					ft_read(int fd, char *buff, char **str, char *left_over);
char				*ft_check(char *str, char *left_over, char *buff, int *t);
int					get_line(const int fd, char **line, char *left_over);
int					get_next_line(const int fd, char **line);

/*
** ft_printf
*/

int				ft_printf(char *format, ...);

#endif
