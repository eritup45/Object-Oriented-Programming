#include <iostream>  
#include <cmath>  
#include<iomanip>  
using namespace std;  
   
int main() {  
    double num[11];  
    long long int count=0;  
    double sum = 0;  
    double cube = 2;  
    for(int i = 0;i<sizeof(num)/sizeof(num[0]);i++){  
        if(cin >> num[i]){  
            count++;  
        }  
    }  
   
    for(int i = 0;i<count;i++){  
        sum = sum + pow(num[i],cube);  
    }  
    sum = sum * 1000000 + 0.5;  
    sum = floor(sum)/1000000;     
    cout << fixed << setprecision(6) << sum << endl;  
    sum=0;  
    return 0;  
}  