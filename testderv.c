#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "derv.h"

#define HZ 250
#define FREQ 2
#define BUF (BUFSIZ/8)

int main()
{
	int16_t data[BUF];
	int i;
	double phi0 = 0.0;
	double h = 1.0 / HZ;

	for (i = 0; i < BUF; i++)
		data[i] = (int16_t)
			1000 * sin(phi0 + 2.0 * M_PI * FREQ * i * h);

	getderv_int16_t(data, BUF);

	for (i = 0; i < BUF; i++)
		printf("%hd\n", data[i] * HZ);

	return 0;
}
