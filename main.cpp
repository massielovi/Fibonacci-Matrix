#include <iostream>
#include <math.h>

using namespace std;

void Mult(int A[2][2], int B[2][2]) {
  int C[2][2];
   for(int i=0;i<2;i++){
     for(int j=0;j<2;j++){
       C[i][j]=0;
       for(int k=0;k<2;k++){
         C[i][j]=C[i][j]+A[i][k]*B[k][j];
        }
      }
    }
   A[0][0] = C[0][0];
   A[0][1] = C[0][1];
   A[1][0] = C[1][0];
   A[1][1] = C[1][1];
}

void Pow(int F[2][2], int n) {
   if(n == 1)return;
  
   int M[2][2] = {{0,1},{1,1}};
   Pow(F, n / 2);
   Mult(F, F);
  
   if(n % 2 != 0)Mult(F, M);
}

int Fibo(int n) {
   int F[2][2] = {{0,1},{1,1}};
  
   if(n == 0)return 0;
  
   Pow(F, n - 1);
   return F[1][0];
}
int main() {
   int n=13;
   cout<<Fibo(n+1)<<endl;
   return 0;
}
