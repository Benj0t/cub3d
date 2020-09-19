/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:18:22 by marvin            #+#    #+#             */
/*   Updated: 2020/09/20 01:05:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_pmlx pmlx;

	set_null(&pmlx);
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
			ft_puterr("Error", &pmlx, 1);
		if (!(ft_parse(&pmlx, argv[1])) || pmlx.s.n_key != 8)
			ft_puterr("Error", &pmlx, 1);
		if (!(create_map(&pmlx)) || (!convert_map(&pmlx)))
			ft_puterr("Error", &pmlx, 1);
		if (!(get_pos(&pmlx)) || !(valid_map(&pmlx)) || !(check_tex(&pmlx)))
			ft_puterr("Error", &pmlx, 1);
		if (!sprites_tab(&pmlx))
			ft_puterr("Error", &pmlx, 1);
		if (argc == 3)
			pmlx.screenshot = 1;
		raycast(&pmlx);
	}
	else
	{
		ft_puterr("Error", &pmlx, 1);
	}
}
