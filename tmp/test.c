#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char	*ft_conv_hex(int nb)
{
	char	*base = "0123456789ABCDEF";
	char	*str;
	int		len;
	int		mult;
	int		count;
	int		s_nb;

	len = (nb == 0) ? 1 : nb / 16 + 1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return(NULL);
	str[len--] = '\0';
	mult = 1;
	while (nb > 0 && nb >= 16)
	{
		s_nb = nb;
		count = 0;
		while ()
	}
	str[i] = base[nb];
	return(str);
}

/*
char **ft_hex(int **buffer)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buffer[x])
	{
		while(buffer[x][y])
			y++;
		x++;
	}
	char tab[x][y];
	x = -1;
	y = -1;
	while (buffer[++x])
		while(buffer[x][++y])
			tab[x][y] = ft_conv_hex(buffer[x][y]);
	return(tab);
}
*/
int main()
{
	printf("%s\n", ft_conv_hex(42));
}