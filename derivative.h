#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 //derivatives are cool
 //h fark metodlarında kullanılan farkı belirler
//*f türev alınıcak fonksiyonun adresini tutar
double forwardDifference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}
double backwardDifference(double (*f)(double), double x, double h) {
    return (f(x) - f(x - h)) / h;
}

double centralDifference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}


