#include <iostream>    
#include <cmath>    
using namespace std;    
//借计 
int main(){    
     int num, count;    
     while(cin >> num){  
         for(int j = 1;j <= num;j++){    
              if(num % j == 0){    //璸衡砆埃荷Ω计
                   count++;    
              }    
         }    
         if(count == 2){    //单Τ1㎝计セō
              cout << "YES" << endl;    
         }    
         else{  
            cout << "NO" << endl;    
         }  
         count = 0;    
     }  
}  