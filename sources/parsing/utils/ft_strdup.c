/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:20:05 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/27 18:33:49 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_strdup_n(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
