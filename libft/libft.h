/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:41:07 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/06 21:00:46 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 8
# define FD_MAX 4864
# define FT_INTMAX 2147483647

# define MIN(a,b) ((a) > (b) ? (b) : (a))
# define MAX(a,b) ((a) > (b) ? (a) : (b))
# define ABSOLUTE(a) (((a) < 0) ? -1 * (a) : (a))
# define AVG(a,b) (((a) - (b)) / 2) + (b)
# define DIFF(a,b) MAX((a), (b)) - MIN((a), (b))

# define P_RD "\e[38;5;203m"
# define P_YW "\e[38;5;220m"
# define P_GR "\e[38;5;112m"
# define P_BL "\e[38;5;39m"
# define P_PR "\e[38;5;141m"
# define P_GY "\e[38;5;240m"
# define P_X "\e[0m"

typedef struct s_list	t_list;
struct	s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

/*
** PART ONE FUNCTIONS
*/

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char*s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** PART TWO FUNCTIONS
*/

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
** BONUS FUNCTIONS
*/

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *st, t_list *(*f)(t_list *elem));

/*
** EXTRA FUNCTIONS
*/

size_t	ft_numlen(int n);
void	ft_putlist(t_list **head);
void	ft_putnode(t_list *node);
void	ft_putarray(char **array);
int		ft_wordcount(const char *s, char c);
int		ft_iswhitespace(int c);
char	*ft_strnchr(const char *s, int c, size_t n);
char	*ft_strcjoin(char const *s1, char const *s2, char c);
int		ft_round(double num);
char	*ft_base(int num, int base);
int		get_next_line(const int fd, char **line);
int		ft_ishexdigit(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_atoibase(char *str, int base);
char	*ft_strjoinfree(char *old, char *new);
char	*scoot(char *string, char delimiter);
#endif
