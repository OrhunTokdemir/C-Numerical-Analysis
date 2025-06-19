#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//havent implemented a check for the matrix to be diagonally dominant
float* GaussSiedel(float*A,float*b,float*xk,int n,int max_iter,float hata){
    float *xkp = (float*)calloc(n , sizeof(float));
    float max_dif=0.0f,temp=0.0f;
    //xkp means x(k+1) p stands for plus
    for(int iterasyon=0;iterasyon<max_iter;iterasyon++){
        for(int i=0;i<n;i++){
            xkp[i]=b[i];
            for(int j=0;j<n;j++){
                if(j<i){
                    xkp[i]-=A[n*i+j]*xkp[j];
                }
                if(j>=i+1){
                    xkp[i]-=A[n*i+j]*xk[j];
                }
            }
            xkp[i]/=A[n*i+i];
        

        }
        
        for(int i=0;i<n;i++){
            temp=fabs(xkp[i]-xk[i])/fabs(xkp[i]);
            if(temp>max_dif){
                max_dif=temp;
            }
        }
        if(max_dif<hata){
            break; // If the maximum difference is less than the tolerance, exit the loop
        }
        
        for(int i=0;i<n;i++){
            xk[i]=xkp[i]; // Update xk with the new values
        }
        
    }
    return xkp; // Return the updated solution vector

}
int main(){
    float A[3][3]={
        {15.0f,5.0f,-5.0f},
        {5.0f,20.0f,10.0f},
        {-5.0f,5.0f,15.0f}
    };
    float ba[3]={29.0f,-3.0f,-7.0f};
    float xk[3]={2.0f,-1.0f,1.0f};
    float* xresult=GaussSiedel((float*)A, (float*)ba, (float*)xk, 3, 10, 0.01f);
    for(int i=0;i<3;i++){
        printf("x[%d]=%f\n",i+1,xresult[i]);
    }
    return 0;
}