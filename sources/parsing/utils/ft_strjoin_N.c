#include "../../../includes/cub3d.h"

char	*ft_strjoin_N(char *s1, char *s2, int len)
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