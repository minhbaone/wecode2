// 1 số mẫu test: => random 1 mảng 1 chiều có số lượng phần tử từ ít tới nhiều
// 10 phần tử, 100 phần tử, 1,000, 10,000, 100,000 phần tử
#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#define MAXN 500000
using namespace std;

double ThuatToan1(int a[], int n) {
    clock_t begin;
    clock_t end;
    begin = clock(); 
    int maxSum = 0;
    for(int i = 0; i < n; i++ )
        for(int j = i; j < n; j++) {
            int thisSum = 0;
            for(int k = i; k <= j; k++ )
                thisSum += a[k];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    end = clock(); 
    return ((double)end-begin)/CLOCKS_PER_SEC ;
}

float ThuatToan4(int a[], int n) {
    clock_t begin;
    clock_t end;
    begin = clock(); 
    int maxSum = 0, thisSum = 0;
    for( int j = 0; j < n; j++ ) {
        thisSum += a[j];
        if ( thisSum > maxSum )
            maxSum = thisSum;
        else if ( thisSum < 0 )
            thisSum = 0;
    }
    cout << "  Max " << maxSum ;
    end = clock(); 
    return ((float)end-begin)/CLOCKS_PER_SEC ;
}

void RandomArray(int a[], int n){
    srand (time(NULL));
    for(int i=0 ; i< n ; i++){
         a[i]=rand()%1000-600; // Ghi chú tạo ds có số âm, số dương
    }
}
int main(){
    int a[MAXN], n ;
    float t1,t2;
    int test[10]={10, 100, 1000, 10000, 100000, 200000, 300000, 400000, 500000}, ntest=9;
    cout << "Hello" << endl ;
    for(int i=0  ; i < ntest ; i++){
        n=test[i];
        cout <<"Thuan toan 4 test: "<<test[i];
        RandomArray(a, n);
        //t1=ThuatToan1(a,n); 
        t4=ThuatToan4(a, n); 
        cout << "  Thoi gian: " << t4 << endl; ;
    }
    
    return 0;
}

