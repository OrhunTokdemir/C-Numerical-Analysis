#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "common.h"
#include "derivative.h"

double function(double x) {
    //e^-x -x = 0;
    return pow(E,-x)-x;
}
//turevi bulmak icib basit bir orta fark fonksiyonu kullanmaktayım. 3. parti bir kutuphane kullanmak yerine
//kendi fonksiyonumu yazmayı tercih ettim. turev hesabının kesinliği bu durmda fonksiyonun yaklasım dogrulugunu azaltmakta
double setX1 (double (*f)(double), double x0, double h) {
    return x0 - f(x0) / centralDifference(f, x0, h);
}

int NewtonRaphson(double (*f)(double), double x0, double h,double hata,int max_step){
    double x1=setX1(f, x0, h);
    //h turev yaklaşımında kullanılan fark değeri

    int step = 0;
    while(!bagilHata(x1, x0, hata)&& step < max_step) {
        goster_alt(x1, x0, f, step);
        
            x0 = x1;
        x1 = setX1(f, x0, h);
        step++;
    }
    printf("kok bulundu:%0.12lf\n",x1);
    return 0;
}
int main(){
    NewtonRaphson(function, 0, 0.001, 0.0001,30);
    system("pause");
    return 0;
}