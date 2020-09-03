/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:58:05 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:28:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		leng;
	char	*str;

	i = 0;
	leng = ft_strlen(s);
	if (!s || (!(str = (char *)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	if (!(leng < start))
		while (len-- > 0 && i < leng)
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
