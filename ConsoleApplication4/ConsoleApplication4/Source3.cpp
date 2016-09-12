#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

double getrandom(double min, double max) {
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;

	return temp;
}

bool isinellipse(double x, double y) {
	double x_e = 2.0, y_e = 1.0, a = 2.0, b = 1.0;
	double tf = ((x - x_e)*(x - x_e)) * (b*b) + ((y - y_e)*(y - y_e)) * a*a-a*a*b*b;
	if (tf > 0.0) return false;
	else return true;
}

void main() {
	FILE *of = fopen("elipse.txt", "w");

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 1000; i++) {
		double x = getrandom(0.0, 4.0);
		double y = getrandom(0.0, 2.0);

		if (isinellipse(x, y) == true)
			fprintf(of, "%f %f\n", x, y);
	}
	fclose(of);
}