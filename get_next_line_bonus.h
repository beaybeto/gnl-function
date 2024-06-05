/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:01:18 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/06/05 15:18:09 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*join(char *memory, char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);

#endif