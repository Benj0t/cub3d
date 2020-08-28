/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_N.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:59:03 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 11:59:43 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_strjoin_n(char *s1, char *s2, int len)
{
	char	*pt;
	int		i;
	int		j;

	if ((!(pt = malloc(sizeof(char) * (len + 2)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		pt[i++] = s1[j++];
	j = 0;
	while (s2[j])
		pt[i++] = s2[j++];
	pt[len] = '\n';
	pt[len + 1] = '\0';
	return (pt);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*pt;
	int		i;
	int		j;

	if ((!(pt = malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		pt[i++] = s1[j++];
	j = 0;
	while (s2[j])
		pt[i++] = s2[j++];
	pt[len] = '\0';
	return (pt);
}
