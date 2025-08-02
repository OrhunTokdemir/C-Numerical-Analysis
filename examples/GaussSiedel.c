#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int CheckDiagonallyDominant(float* A, float* b, int n){
    // This function checks if the matrix is diagonally dominant
    float* temp=(float*)malloc(n*sizeof(float));
    float temp2=0.0f;
    //calculate the sum of the absolute values of each row
    //and check if the diagonal element is greater than half of the sum of the absolute values
    // base condition for Gauss-Seidel method to converge is |aii|>sum(|aij|) ,i!=j
    //in that sense |aii|>sum(|aij|)-|aii| therefore |aii|>sum(|aij|)/2
    for(int i=0;i<n;i++){
        float sum=0.0f;
        for(int j=0;j<n;j++){
            sum+=fabs(A[n*i+j]);
        }
        //if the row is already diagonally dominant, continue to the next row
        if(fabs(A[n*i+i])>sum/2){
            continue;
        }
        //if the row is not diagonally dominant, swap the row with another row that has a larger diagonal element
        for(int k=0;k<n;k++){
            if(fabs(A[n*i+k])>sum/2){
                temp2=b[i];
                b[i]=b[k];
                b[k]=temp2;
                for(int l=0;l<n;l++){
                    temp[l]=A[n*i+l];
                    A[n*i+l]=A[k*n+l];
                    A[n*k+l]=temp[l];
                    
                }
                break;
            }
        }
    }
    free(temp);
    for (int i = 0; i < n; i++) {
        float sum = 0.0f;
        for (int j = 0; j < n; j++) {
            sum += fabs(A[n * i + j]);
        }
        if (fabs(A[n * i + i]) <= sum / 2) {
            return 0; // Failed to make it diagonally dominant
        }
    }
    return 1; // Diagonally dominant
}
//if the the matrix being diagonally dominant isn't known, it should be checked and rearranged using the CheckDiagonallyDominant function.
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
        {-5.0f,5.0f,15.0f},
        {5.0f,20.0f,10.0f}
    };
    float ba[3]={29.0f,-7.0f,-3.0f};
    float xk[3]={2.0f,-1.0f,1.0f};
    if(CheckDiagonallyDominant((float*)A, ba, 3)){
        
        float* xresult=GaussSiedel((float*)A, (float*)ba, (float*)xk, 3, 10, 0.01f);
        for(int i=0;i<3;i++){
            printf("x[%d]=%f\n",i+1,xresult[i]);
            
        }
    }
    
    
    //dont forget to free allocated memory.
    return 0;
}