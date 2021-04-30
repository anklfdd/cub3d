/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:48:55 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 19:57:53 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int					ft_atoi(const char *str);
int					ft_isalnum(int sym);
int					ft_isalpha(int sym);
int					ft_isascii(int sym);
int					ft_isdigit(int sym);
int					ft_isprint(int sym);
int					ft_tolower(int sym);
int					ft_toupper(int sym);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
int					ft_memcmp(const void *str1, const void *str2, size_t num);
int					ft_lstsize(t_list *lst);
void				*ft_memccpy(void *dst, const void *src, int asc,
						size_t num);
void				ft_bzero(void *str, size_t num);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *str, int asc, size_t num);
void				*ft_memcpy(void *dst, const void*src, size_t num);
void				*ft_memmove(void *dst, const void *src, size_t num);
void				*ft_memset(void *str, int sym, size_t num);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_free_w(char **word);
void				ft_lst_free(t_list **lst);
char				*ft_strchr(const char *str, int sym);
char				*ft_strdup(const char *str);
char				*ft_itoa(int n);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strrchr(const char *str, int sym);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t sz);
size_t				ft_strlcpy(char *dst, const char *src, size_t sz);
size_t				ft_strlen(const char *str);
size_t				ft_count(long int n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstnew_size(void *content, size_t size);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
size_t				ft_strchr_gnl(const char *str, int sym);
char				*ft_strlcpy_gnl(char *dst, const char *src, size_t sz);
int					get_next_line(int fd, char **line);
char				*strjoin_data_buf(char *data, char *buf);
#endif
