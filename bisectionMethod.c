#include<stdio.h>
#include "common.h"



void bisectionMethod(double a,double b, double hata){
    while(!checkRoot(a,b)){
        printf("Verilen degerler arasinda kok yoktur. yeniden deger giriniz.\n");
        printf("a:");
        scanf("%lf",&a);
        printf("\nb:");
        scanf("%lf",&b);
    }
    int state=mutlakHata(a,b,hata);
    while (!mutlakHata(a,b,hata)) {
        double p0=(a+b)/2;
        if(checkRoot(a,p0)){
            goster(a,p0,mutlakHata(a,b,hata));
            b=p0;
        }
        else if(checkRoot(p0,b)){
            a=p0;
        }
        
    }
}

int main(){
    
    system("pause");
    return 0;
}