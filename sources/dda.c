#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double    degtorad(double deg)
{
    return deg * 0.0174532925;
}

int *dda(int py, int px, char **tab, int alpha)
{
	int ax;
	int ay;
	int varx;

	ay = (alpha < 180) ? (py / 64) * (64) - 1 : (py / 64) * (64) + 64;
	ax = px + (py - ay) / tan(degtorad(alpha));
	write(1, "1\n", 2);
	varx = 64 / tan(degtorad(alpha));
	write(1, "1\n", 2);
	//printf("1tab: y:%d | x:%d =>  %c\n",ay/64, ax/64, tab[ay / 64][ax / 64]);
	while (tab[ay / 64][ax / 64] != '1')
	{
		write(1, "2\n", 2);
		ax += (alpha < 180) ? -varx : varx;
		ay += (alpha < 180) ? -64 : 64;
		printf("2tab: y:%d | x:%d =>  %c\n",ay/64, ax/64, tab[ay / 64][ax / 64]);
	}
	write(1, "1\n", 2);
	int *tableau;
	if (!(tableau = (int *)malloc(sizeof(int) * (2))));
	tableau[0] = ay;
	tableau[1] = ax;
	write(1, "1\n", 2);
	return (tableau);
}

int main()
{
	char *tab[5];

	tab[0] = "111111111111";
	tab[1] = "100000000001";
	tab[2] = "100000000001";
	tab[3] = "1P0000000001";
	tab[4] = "111111111111";
	int *tableau = dda(224, 160, tab, 360);
	printf("EXIT: %d | %d\n", tableau[0], tableau[1]);
	printf("0: %f\n 90: %f\n 180: %f\n 270: %f\n 360: %f\n", tan(degtorad(0)), tan(degtorad(90)), tan(degtorad(180)), tan(degtorad(270)), tan(degtorad(360)));
}