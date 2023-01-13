#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum1 = 0;
    double sum2 = 0;
    double max = A[0],min = A[0];
    double G = 1;
    double H = 0;
    double Q;

    for(int i=0;i<N;i++){
        sum1 += A[i];
    }
    B[0] = sum1/N;

    for(int j=0;j<N;j++){
        sum2 += pow(A[j]-B[0],2);
        Q = sum2/N;
    }
    B[1] = sqrt(Q);

    for(int k=0;k<N;k++){
        G *= A[k];
    }
    B[2] = pow(G,(1.0/N));

    for(int l=0;l<N;l++){
        H += (1/A[l]);
    }
    B[3] = N/H;

    for(int m=0;m<N;m++){
        if (A[m] > max) 
            max = A[m];
        if (A[m] < min)
            min = A[m];   

    }
    B[4] = max;
    B[5] = min;
}