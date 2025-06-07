#include<stdlib.h>
#define E 2.71828
#define PI_ 3.14159
//yaklasim yapılacak fonksiyon kod icerinde burda belirleniyor.
double f(double x) {
    return x * x - 4; 
}

int mutlakHata(double p1,double p0,double hata) {
    if(abs(p1-p0)<hata){
        return 1;
    } else {
        return 0;
    }
}

int bagilHata(double p1,double p0,double hata) {
    if(abs(p1-p0)/abs(p0)<hata){
        return 1;
    } else {
        return 0;
    }
}
int checkRoot(double a, double b) {
    int pn = (a+b) / 2;
    if (f(a) * f(b) < 0) {
        return 1; // There is a root in the interval [a, b]
    } else {
        return 0; // No root in the interval
    }   
}
void goster(double a, double b, double mutlakHata) {
    printf("a: %lf\n", a);
    printf("pn:%lf\n",(a + b) / 2);
    printf("b: %lf\n", b);
    printf("Hata: %lf\n_________________________________", mutlakHata);
}