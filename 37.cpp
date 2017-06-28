// 37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <graphics.h>
#include <math.h>
#include <complex.h>
#include <conio.h>

int main() {
	double a = 0.85, b = 0.9, k = 0.5, p = 7.7; //константы. При изменении их будет модифицироваться изображение
	complex z;
	int gd = DETECT, gm;
	int i;
	initgraph(&gd, &gm, "G:\\programs\\BC31\\BGI"); // инициализируем графику
	z = 0;
	for (i = 0; i <= 30000; i++) {
		z = a + b*z*exp(complex(0, (k - p / (1 + abs(z*z))))); // формула, по которой рисуем
		putpixel(real(z) * 180 + 240, imag(z) * 180 + 280, 14); //ставим точку на экране
	}
	getch(); // пауза для задержки изображения на экране
	closegraph();
	return 0;
}

