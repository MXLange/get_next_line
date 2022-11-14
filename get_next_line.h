/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msprenge <msprenge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:38:33 by msprenge          #+#    #+#             */
/*   Updated: 2022/11/14 16:54:02 by msprenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strchr(const char *s, int c); // ok
char	*ft_strjoin(char const *s1, char const *s2); //ok
size_t	ft_strlen(const char *s); //ok
void	*ft_calloc(size_t nmemb, size_t size); //ok
char	*get_next_line(int fd); //para os testes;

#endif
