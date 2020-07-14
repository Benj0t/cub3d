#include "../../../includes/parsing.h"

char	*ft_substr(char *s, int start, int len)
{
	int	i;
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