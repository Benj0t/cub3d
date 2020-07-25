/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:51:27 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 16:37:17 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
