/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <aio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

// ==========
// char
// ==========

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);

// ==========
// conv
// ==========

int				ft_atoi(const char *nptr);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa(int n);

// ==========
// file
// =========

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# elif BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be bigger than 0"
# endif

typedef struct t_lsti {
	struct t_lsti		*next;
	ssize_t				offset;
	ssize_t				size;
	int					fd;
	char				cache[BUFFER_SIZE];
}	t_lsti;

typedef struct t_line
{
	ssize_t					current_size;
	ssize_t					idx;
	char					*data;
}	t_line;

int				ft_gnl(int fd, char **dest);

t_lsti			*ft_gnl_get_cached(int fd);
void			ft_gnl_del_cached(int fd);
void			ft_gnl_clear_cache(void);
// ==========
// float
// ==========

float			ft_maxf(float a, float b);

float			ft_minf(float a, float b);

// ==========
// int
// ==========

int				ft_max(int a, int b);
size_t			ft_maxlu(size_t a, size_t b);

int				ft_min(int a, int b);
size_t			ft_minlu(size_t a, size_t b);

// ==========
// lst
// ==========

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

// ==========
// mem
// ==========

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_free_matrix(void **matrix);
void			ft_free_matrix_del(void **matrix, void del (void *));
void			*ft_realloc(void *ptr, size_t current_size, size_t new_size);
void			*ft_realloc_del(void *ptr, size_t current_size, size_t new_size,
					void del (void *));
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

// ==========
// put
// ==========

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_putbase_fd(uint64_t num, const char *base_chars, int fd);
int				ft_putchar_fd(char c, int fd);
int				ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putunbr_fd(unsigned int n, int fd);

// ==========
// str
// ==========

void			ft_free_stra(char **arr);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
