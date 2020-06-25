/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:49:14 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/07 09:39:42 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_char(char c, char *base)
{
	int j;

	j = -1;
	while (base[++j])
		if (base[j] == c)
			return (1);
	return (-1);
}

int		ft_check(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
		i++;
	if (i <= 1)
		return (-1);
	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
			if (base[i] == base[j++])
				return (-1);
		i++;
		j = i + 1;
	}
	i = -1;
	while (base[++i])
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ' ||
			base[i] == '-' || base[i] == '+')
			return (-1);
	return (1);
}

int		ft_check_pos(char pos, char *base)
{
	int i;

	i = 0;
	while (pos != base[i])
		i++;
	return (i);
}

int		ft_calc(char *base, char *str, int i)
{
	int len;
	int len_base;
	int mult;
	int nb;

	nb = 0;
	mult = 1;
	len = i;
	len_base = 0;
	while (base[len_base])
		len_base++;
	while (str[len] && (str[len] != ' ' && str[len] != '-' &&
			ft_check_char(str[len], base) == 1 && str[len] != '+' &&
			(!(str[len] <= 13 && str[len] >= 9))))
		len++;
	while (--len >= i)
	{
		nb += ft_check_pos(str[len], base) * mult;
		mult *= len_base;
	}
	return (nb);
}

int		ft_atoi_base(char *str, char *base)
{
	int nb;
	int i;
	int count;

	i = 0;
	count = 0;
	if (ft_check(base) < 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		count += (str[i] == '-') ? 1 : 0;
		i++;
	}
	nb = ft_calc(base, str, i);
	return ((count % 2 == 0) ? nb : -nb);
}
