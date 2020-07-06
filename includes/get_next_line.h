/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:57:49 by bemoreau          #+#    #+#             */
/*   Updated: 2019/12/18 18:41:44 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define OPEN_MAX 4096

typedef struct		s_struct
{
	int				len;
	int				ret;
	int				pos;
	char			*buffer;
	char			*tmp;
	char			*s[OPEN_MAX];
}					t_struct;

int					ft_strlen(char *str);
int					get_next_line(int fd, char **line);
char				*ft_calloc(int count, int size);
char				*ft_strdup(char *src, int len);
char				*ft_substr(char *s, unsigned int start,
					size_t len, int bool);
char				*ft_strjoin(char *s1, char *s2, int len);

#endif
