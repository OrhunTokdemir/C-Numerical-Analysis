#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define E 2.71828
#define PI_ 3.14159
//yaklasim yapılacak fonksiyon kod icerinde burda belirleniyor.
double f(double x) {
    return x-pow(2,-x); 
}

int mutlakHata(double p1,double p0,double hata) {
    if(fabs(p1-p0)<hata){
        return 1;
    } else {
        return 0;
    }
}

int bagilHata(double p1,double p0,double hata) {
    if(fabs(p1-p0)/fabs(p0)<hata){
        return 1;
    } else {
        return 0;
    }
}
int checkRoot(double a, double b) {
    if (f(a) * f(b) < 0) {
        return 1; // There is a root in the interval [a, b]
    } else {
        return 0; // No root in the interval
    }   
}
void goster_tekli(double xn, double (*f)(double), int step) {
    printf("\n_________________________________\n");
    printf("Adim: %d\n", step);
    printf("x%d: %0.12lf\n", step, xn);
    printf("f(x%d): %0.12lf\n", step, f(xn));
    }

void goster_alt(double x1,double x0,double(*f)(double),int step){//alternatif gosterme fonksiyonu
    printf("\n_________________________________\n");
    printf("Adim: %d\n", step);
    printf("x%d: %0.12lf\n",step , x0);
    printf("x%d: %0.12lf\n",step+1, x1);
    printf("f(x%d): %0.12lf\n", step, f(x0));
    printf("f(x%d): %0.12lf\n", step+1, f(x1));
    printf("\n_________________________________\n");

}
void goster(double a, double b,double fpn,int* step, double pn) {
    printf("\n_________________________________\n");
    printf("Adim: %d\n", (*step)++);
    printf("a: %0.12lf\n", a);
    printf("pn:%0.12lf\n",pn);
    printf("b: %0.12lf\n", b);
    printf("f(pn):%0.12lf",fpn);
    printf("\n_________________________________");
}