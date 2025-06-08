#include<stdio.h>
#include<stdlib.h>
#include "common.h"
//this is the recursive implementations of regula falsi method
//i just wanted to make it in recursive.
//i will probably make a version of this using while loops later.
int regulaFalsiMethod(double a, double b, double hata);
int* adim = NULL;

int main() {
    regulaFalsiMethod(0, 1, 0.00001);
    free(adim); 
    system("pause");
    return 0;
}

int regulaFalsiMethod(double a, double b, double hata) {
    if (!adim) {
        adim = (int*)malloc(sizeof(int));
        *adim = 1; // Initialize step counter
    }
    

    
    
    int state = mutlakHata(a, b, hata) || bagilHata(a, b, hata);
    
    if (state) {
        isZero:
        printf("Mutlak hata saglandi.\n");
        return 0;
    }
    
    double pn = (a * f(b) - b * f(a)) / (f(b) - f(a)); // Regula Falsi formula
    if(!f(pn)) {
        goto isZero;
    }
    goster(a, b, f(pn), adim,pn);
    
    if (checkRoot(a, pn)) {
        b = pn;
        regulaFalsiMethod(a, b, hata);
    } else if (checkRoot(pn, b)) {
        a = pn;
        regulaFalsiMethod(a, b, hata);
    } else {
        printf("Kok bulunamadi.\n");
        return 0;
    }
}
