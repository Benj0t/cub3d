#include "cub3d.h"

//__attribute__((destructor)) void foo(void){while (1); }

 int		main(int argc, char **argv)
{
	t_pmlx pmlx;

	set_null(&pmlx);
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strcmp(argv[2], "--save"))
			ft_puterr("Invalid second argument", &pmlx);
		if (!(ft_parse(&pmlx, argv[1])) || pmlx.s.n_key != 8)
			ft_puterr("Parsing error", &pmlx);
		if (!(create_map(&pmlx)) || (!convert_map(&pmlx)))
			ft_puterr("Map creation error", &pmlx);
		if (!(get_pos(&pmlx)) || !(valid_map(&pmlx)) || !(check_tex(&pmlx)))
			ft_puterr("Map invalid", &pmlx);
		if (!sprites_tab(&pmlx))
			ft_puterr("Sprites creation error", &pmlx);
		if (argc == 3)
			pmlx.screenshot = 1;
		raycast(&pmlx);
	}
	else
	{
		ft_puterr("Invalid Number of Arguments\n", &pmlx);
	}
}
