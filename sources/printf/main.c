#include "libftprintf.h"
#include <stdio.h>
// 0 = Type d arg | 1 = Length | 2 = Prec | 3 = Start | 4 = End | 5 = Minus | 6 = Flag 0 | 7 = LEN * | 8 = PREC * | tab[9] = ??? | tab[10] = POINT | tab[11] = %s prec < 0 |
// c s p d i u x X %

int		main()
{
	char *str;
	str = "allo maman bobo";
	//printf("   %d\n", printf("%0*.*u, %*.*x, %*.*X, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d",19,14, -42, 19,14, 42, 19,14, -42, 19,14, 42, 19,14, -42, 19,14, -42, 19,14, -42,19,14, -42));
	//printf("   %d\n", ft_printf("%0*.*u, %*.*x, %*.*X, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d",19,14, -42, 19,14, 42, 19,14, -42, 19,14, 42, 19,14, -42 ,19,14, -42,19,14, -42,19,14, -42));
	printf("   %d\n",    printf("|%0c|%1.3s|%p|%5.3d|%5.3i|%10.0u|%3.2x|%2.3X|%d|", 102, str, &str, 42, 42, 214748364, 42, -42, -2147483648));
	printf("   %d\n", ft_printf("|%0c|%1.3s|%p|%5.3d|%5.3i|%10.0u|%3.2x|%2.3X|%d|", 102, str, &str, 42, 42, 214748364, 42, -42, -2147483648));
	system("leaks a.out");
	return(0);
}