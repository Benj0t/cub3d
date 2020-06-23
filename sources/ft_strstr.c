int		ft_strstr(char *src, char *to_find)
{
	int i;
	int y;

	i = 0;
	while (src[i])
	{
		y = 0;
		while (src[i] == to_find[y])
		{
			i++;
			y++;
			if (!to_find[y])
				return (1);
		}
		i = i -  y + 1;
	}
	return (0);
}