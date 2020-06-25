/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:56:28 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/28 19:53:07 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstrr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pt;
	int		i;
	int		j;

	if ((!s1 || !s2) ||
		(!(pt = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		pt[i++] = s1[j++];
	j = 0;
	while (s2[j])
		pt[i++] = s2[j++];
	pt[i] = '\0';
	free(s1);
	return (pt);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || (!(str = (char *)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	if (!((unsigned int)ft_strlen(s) < start))
		while (len-- > 0 && i < (size_t)ft_strlen(s))
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
