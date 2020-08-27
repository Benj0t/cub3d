/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 01:53:44 by marvin            #+#    #+#             */
/*   Updated: 2020/08/27 18:32:16 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void		ft_fill(char *tab, char *str, int n, int *i)
{
	int j;

	j = 0;
	while ((str[*i] == '\n' || str[*i] == '\t' || str[*i] == ' ') &&\
		str[*i] != '\0')
		*i = *i + 1;
	while (str[*i] != '\0' && j <= n)
	{
		if ((str[*i] == '\n' || str[*i] == '\t' || str[*i] == ' ') &&\
			str[*i] != '\0')
			*i = *i + 1;
		else
		{
			tab[j] = str[*i];
			*i = *i + 1;
			if (j < n)
				j++;
			if (j >= n)
				return ;
		}
	}
}

int			ft_count_letters(char *str, int *i)
{
	int j;

	j = 0;
	while ((str[*i] == '\n' || str[*i] == '\t' || str[*i] == ' ') &&\
		str[*i] != '\0')
		*i = *i + 1;
	while (str[*i] != '\n' && str[*i] != '\t' && str[*i] != ' ' &&\
		str[*i] != '\0')
	{
		j++;
		*i = *i + 1;
	}
	while ((str[*i] == '\n' || str[*i] == '\t' || str[*i] == ' ') &&\
		str[*i] != '\0')
		*i = *i + 1;
	return (j);
}

int			ft_skip_whitespaces(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' &&\
			str[i] != '\0')
			j = j + 1;
		while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' &&\
			str[i] != '\0')
			i++;
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
	}
	return (j);
}

static char	**split_free(char **tab, int j, t_pmlx *pmlx)
{
	ft_putendl("Malloc failed (ft_split)");
	while (--j >= 0)
	{
		free(tab[j]);
	}
	free(tab);
	err_parsing(pmlx);
	return (NULL);
}

char		**ft_split(char *str, t_pmlx *pmlx)
{
	int		i;
	int		j;
	int		h;
	t_vec	tmp;
	char	**tab;

	if (!str || ft_strlen(str) == 0)
		return (NULL);
	tmp.x = 0;
	tmp.y = 0;
	i = ft_skip_whitespaces(str);
	j = -1;
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 1))))
		ft_puterr("Malloc failed (ft_split)", pmlx);
	tab[i] = NULL;
	while (++j < i)
	{
		h = ft_count_letters(str, &(tmp.x));
		if (!(tab[j] = (char*)malloc(sizeof(char) * (h + 1))))
			return (split_free(tab, j, pmlx));
		tab[j][h] = '\0';
		ft_fill(tab[j], str, h, &(tmp.y));
	}
	return (tab);
}
