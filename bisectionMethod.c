#include<stdio.h>
#include<stdlib.h>
#include "common.h"

int bisectionMethod(double a, double b, double hata);
int* adim=NULL;
int main(){
    
    bisectionMethod(0, 5, 0.01);
    system("pause");
    return 0;
}
int bisectionMethod(double a,double b, double hata){
    if(!adim){
        adim = (int*)malloc(sizeof(int));
        *adim = 1; // Initialize step counter
    }
    while(!checkRoot(a,b)&& hata>=0){
        printf("Verilen degerler arasinda kok yoktur. yeniden deger giriniz.\n");
        printf("a:");
        scanf("%lf",&a);
        printf("\nb:");
        scanf("%lf",&b);
        printf("\n*******************\na: %lf\n b: %lf\nhata: %lf\n*******************\n",a,b,hata);
    }
    int state=mutlakHata(a,b,hata);
    if(state){
        printf("Mutlak hata saglandi.\n");
        return 0;
    }
    double pn=(a+b)/2;
    if(checkRoot(a,pn)){
        goster(a,b,f(pn),adim);
        b=pn;
        bisectionMethod(a,b,hata);
    }
    else if(checkRoot(pn,b)){
        goster(a,b,f(pn),adim);
        a=pn;
        bisectionMethod(a,b,hata);
    } else {
        goster(a,b,f(pn),adim);
        printf("Kok bulunamadi.\n");
        return 0;
    }    
    
}
