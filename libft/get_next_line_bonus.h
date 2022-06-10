/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:42:04 by rkedida           #+#    #+#             */
/*   Updated: 2022/05/27 17:19:32 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define BUFFER_SIZE 1000

size_t	ft_strlen1(const char *s);
char	*ft_strchr1(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin1(char *s, char *buff);
char	*ft_next_line(char *protect);
char	*ft_protect(char *protect);
char	*ft_read_protect(int fd, char *protect);

#endif 