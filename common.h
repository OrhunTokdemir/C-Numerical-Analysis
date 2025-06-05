#include<stdlib.h>
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
    if(a*b<0){
        return 1; // Root exists
    } else {
        return 0; // No root exists
    }
}