/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/09 13:07:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

char	*ft_strcat(char *s1, const char *s2); //withit
char	*ft_strchr(const char *s, int c); //withit
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2); //withit
char	*ft_strcpy(char *dst, const char *src); //withit
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1); // SP
int		ft_strequ(char const *s1, char const *s2); //withit
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, const char *s2); // SP
size_t	ft_strlcat(char *dst, const char *src, size_t size); //withit
size_t	ft_strlen(char const *str); //withit
char	*ft_strmap(char const *s, char (*f)(char)); // SP
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // SP
char	*ft_strncat(char *s1, const char *s2, size_t n); //withit
int		ft_strncmp(const char *s1, const char *s2, size_t n); //withit
char	*ft_strncpy(char *dst, const char *src, size_t n); //withit
int		ft_strnequ(char const *s1, char const *s2, size_t n); //withit
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n); //withit
char	*ft_strrchr(const char *s, int c); //withit
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *s1, const char *s2); //withit
char	*ft_strsub(char const *s, unsigned int start, size_t len); // SP
char	*ft_strtrim(char const *s); // SP

#endif
