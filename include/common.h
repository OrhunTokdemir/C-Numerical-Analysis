#ifndef COMMON_H
#define COMMON_H

#define E 2.71828
#define PI_ 3.14159

// Function prototype for the default function
double f(double x);

// Error checking functions
int mutlakHata(double p1, double p0, double hata);
int bagilHata(double p1, double p0, double hata);
int checkRoot(double a, double b);

// Display functions
void goster_tekli(double xn, double (*f)(double), int step);
void goster_alt(double x1, double x0, double (*f)(double), int step);
void goster(double a, double b, double fpn, int* step, double pn);

#endif // COMMON_H